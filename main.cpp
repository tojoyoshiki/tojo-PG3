#include <iostream>
#include <string>
#include <chrono>

int main() {
    //aで初期化された文字列
    std::string a(100000, 'a');

    //コピー時間の計測
    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a;
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto copy_time = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    //移動時間の計測
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a);
    auto end_move = std::chrono::high_resolution_clock::now();
    auto move_time = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    //結果
    std::cout << "100,000文字を移動とコピーで比較しました。\n";
    std::cout << "コピー: " << copy_time << "μs\n";
    std::cout << "移動: " << move_time << "μs\n";
    std::cout << "続行するには何かキーを押してください . . .\n";

    //入力待ちでプログラム終了を防ぐ
    std::cin.get(); 

    return 0;
}
