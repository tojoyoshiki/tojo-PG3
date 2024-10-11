#include <stdio.h>
#include <functional>
#include <time.h>  
#include <thread>    
#include <chrono>    

//3�b�ԑҋ@����SetTimeout�֐�
void SetTimeout(int milliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
	//���������̏���
	srand((unsigned int)time(NULL));

	//�T�C�R���̏o�� (1�`6)
	int diceRoll = rand() % 6 + 1;

	//��������������[�U�[�ɓ��͂��Ă��炤
	int userGuess;
	printf("��Ȃ�1�A�����Ȃ�2����͂��Ă�������: ");
	scanf_s("%d", &userGuess);

	//����֐��i�����_���j���`
	auto checkGuess = [diceRoll](int guess) {
		if ((diceRoll % 2 == 0 && guess == 2) || (diceRoll % 2 != 0 && guess == 1)) {
			printf("������I�T�C�R���̏o�ڂ� %d �ł����B\n", diceRoll);
		}
		else {
			printf("�͂���B�T�C�R���̏o�ڂ� %d �ł����B\n", diceRoll);
		}
	};

	//3�b�ҋ@���Ă��猋�ʂ�\��
	printf("�o�ڂ̌��ʂ��v�Z��...\n");
	SetTimeout(3000);  //3�b�ҋ@
	checkGuess(userGuess);  //���[�U�[�̓��͂��`�F�b�N

	return 0;
}
