#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�R�[���o�b�N�֐��̃v���g�^�C�v�錾
void display_result(int dice_roll, int (*callback)(int));

//����������𔻒肷��R�[���o�b�N�֐�
int check_even_or_odd(int num) {
    return num % 2;
}

//3�b�J�E���g�_�E���֐�
void countdown(int seconds) {
    for (int i = seconds; i > 0; i--) {
        printf("%d...\n", i);
        // clock() ���g�p����1�b�ҋ@
        clock_t start_time = clock();
        while (clock() < start_time + CLOCKS_PER_SEC);
    }
    printf("���ʔ��\�I\n");
}

int main() {
    int user_choice;
    int dice_roll;

    //�V�[�h��ݒ�
    srand(time(NULL));

    // ���[�U�[�Ɋ����������I�΂���
    printf("�T�C�R����U��܂��B�(��)��0�A����(��)��1����͂��Ă�������: ");
    scanf_s("%d", &user_choice);

    //�T�C�R���̏o�ڂ������_���ɐ��� (1����6�͈̔�)
    dice_roll = rand() % 6 + 1;

    //�J�E���g�֐��Ăяo��
    countdown(3);

    //���ʕ\���֐����Ăяo��
    display_result(dice_roll, check_even_or_odd);

    //���[�U�[�̑I���ƌ��ʂ��r
    if (user_choice == check_even_or_odd(dice_roll)) {
        printf("�����ł��I\n");
    }
    else {
        printf("�s�����ł�w�T�C�R���̏o�ڂ�%d�ł���www\n", dice_roll);
    }

    return 0;
}

//�R�[���o�b�N�֐����g�p���Č��ʂ�\��
void display_result(int dice_roll, int (*callback)(int)) {
    if (callback(dice_roll) == 0) {
        printf("�T�C�R���̏o�ڂ�%d�ŁA����(��)�ł��B\n", dice_roll);
    }
    else {
        printf("�T�C�R���̏o�ڂ�%d�ŁA�(��)�ł��B\n", dice_roll);
    }
}
