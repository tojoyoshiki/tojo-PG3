#include <stdio.h>
#include <chrono>    
#include <functional>
#include <time.h>  
#include <thread>    

//3秒間待機するSetTimeout関数
void SetTimeout(int milliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
	srand((unsigned int)time(NULL));

	int diceRoll = rand() % 6 + 1;

	int Guess;
	printf("奇数は1、偶数は2を入力してください: ");
	scanf_s("%d", &Guess);

	auto checkGuess = [diceRoll](int guess) {
		if ((diceRoll % 2 == 0 && guess == 2) || (diceRoll % 2 != 0 && guess == 1)) {
			printf("当たり！サイコロの出目は %d でした！\n", diceRoll);
		}
		else {
			printf("はずれ。サイコロの出目は %d でしたw\n", diceRoll);
		}
	};

	printf("出目の結果を計算中\n");
	SetTimeout(3000);  
	checkGuess(Guess);  

	return 0;
}
