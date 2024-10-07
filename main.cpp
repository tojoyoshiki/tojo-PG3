#include <stdio.h>

//�ċA�I�Ȓ���
double Recursive(int hours) {
    double wage = 100.0; //�ŏ��̎�����100�~
    double total = wage;

    for (int i = 1; i < hours; i++) {
        wage = wage * 2 - 50; //���̎������v�Z
        total += wage; //�������ɉ��Z
    }

    return total;
}

//��ʓI�Ȓ���
double Standard(int hours) {
    const double hourlyWage = 1072.0; // ����1072�~
    return hourlyWage * hours;
}

int main() {
    int hours;

    //�J�����Ԃ���͂��Ă��炤
    printf("���������Ԃ���͂��Ă�������: ");
    scanf_s("%d", &hours);

    //�e�����̌n�Ɋ�Â��Čv�Z
    double recursiveTotal = Recursive(hours);
    double standardTotal = Standard(hours);

    // ���ʂ�\��
    printf("�ċA�I�Ȓ����̌n�ł̑�����: %.2f�~\n", recursiveTotal);
    printf("��ʓI�Ȓ����̌n�ł̑�����: %.2f�~\n", standardTotal);

    //��r
    if (recursiveTotal > standardTotal) {
        printf("�ċA�I�Ȓ����̌n�̕�������\n");
    }
    else if (recursiveTotal < standardTotal) {
        printf("��ʓI�Ȓ����̌n�̕�������\n");
    }
    else {
        printf("�ǂ���̒����̌n�ł�����\n");
    }

    return 0;
}
