#include <stdio.h>
#include <functional>
#include <time.h>  
#include <thread>    
#include <chrono>    

//3秒間待機するSetTimeout関数
void SetTimeout(int milliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
	//乱数生成の準備
	srand((unsigned int)time(NULL));

	//サイコロの出目 (1～6)
	int diceRoll = rand() % 6 + 1;

	//奇数か偶数かをユーザーに入力してもらう
	int userGuess;
	printf("奇数なら1、偶数なら2を入力してください: ");
	scanf_s("%d", &userGuess);

	//判定関数（ラムダ式）を定義
	auto checkGuess = [diceRoll](int guess) {
		if ((diceRoll % 2 == 0 && guess == 2) || (diceRoll % 2 != 0 && guess == 1)) {
			printf("当たり！サイコロの出目は %d でした。\n", diceRoll);
		}
		else {
			printf("はずれ。サイコロの出目は %d でした。\n", diceRoll);
		}
	};

	//3秒待機してから結果を表示
	printf("出目の結果を計算中...\n");
	SetTimeout(3000);  //3秒待機
	checkGuess(userGuess);  //ユーザーの入力をチェック

	return 0;
}
