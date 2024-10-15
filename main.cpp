#include <stdio.h>
#include <chrono>    
#include <functional>
#include <time.h>  
#include <thread>    

//3�b�ԑҋ@����SetTimeout�֐�
void SetTimeout(int milliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
	srand((unsigned int)time(NULL));

	int diceRoll = rand() % 6 + 1;

	int Guess;
	printf("���1�A������2����͂��Ă�������: ");
	scanf_s("%d", &Guess);

	auto checkGuess = [diceRoll](int guess) {
		if ((diceRoll % 2 == 0 && guess == 2) || (diceRoll % 2 != 0 && guess == 1)) {
			printf("������I�T�C�R���̏o�ڂ� %d �ł����I\n", diceRoll);
		}
		else {
			printf("�͂���B�T�C�R���̏o�ڂ� %d �ł���w\n", diceRoll);
		}
	};

	printf("�o�ڂ̌��ʂ��v�Z��\n");
	SetTimeout(3000);  
	checkGuess(Guess);  

	return 0;
}
