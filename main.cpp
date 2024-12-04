#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool dataReady = false;
std::vector<std::vector<int>> mapData;

//CSVファイルを読み込む関数
void loadCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        std::vector<int> row;
        std::string cell;

        while (std::getline(lineStream, cell, ',')) {
            row.push_back(std::stoi(cell));
        }
        mapData.push_back(row);
    }

    file.close();

    //データ読み込み完了を通知
    std::lock_guard<std::mutex> lock(mtx);
    dataReady = true;
    cv.notify_all();
}

//マップチップを表示する関数
void displayMap() {
    std::unique_lock<std::mutex> lock(mtx);

    //データが読み込まれるまで待機
    cv.wait(lock, [] { return dataReady; });

    //マップチップを表示
    for (const auto& row : mapData) {
        for (int cell : row) {
            switch (cell) {
            case 0: std::cout << " . "; break; // 空白
            case 1: std::cout << " # "; break; // 壁
            case 2: std::cout << " @ "; break; // プレイヤー
            default: std::cout << " ? "; break; // 未知
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    const std::string filename = "map.csv";

    //スレッド作成
    std::thread loader(loadCSV, filename);
    std::thread displayer(displayMap);

    //スレッド終了を待機
    loader.join();
    displayer.join();

    return 0;
}
