#include <stdio.h>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int currentThread = 1;

void printThread(int threadId) {
    std::unique_lock<std::mutex> lock(mtx);

    //自分の順番になるまで待機
    cv.wait(lock, [&]() { return currentThread == threadId; });

    //順番が来たらメッセージを出力
    printf("thread %d\n", threadId);

    //次のスレッドを許可
    currentThread++;
    cv.notify_all();
}

int main() {
    //スレッド作成
    std::thread t1(printThread, 1);
    std::thread t2(printThread, 2);
    std::thread t3(printThread, 3);

    //スレッドの終了待ち
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
