#include <stdio.h>

//再帰的な賃金
double Recursive(int hours) {
    double wage = 100.0; //最初の時給は100円
    double total = wage;

    for (int i = 1; i < hours; i++) {
        wage = wage * 2 - 50; //次の時給を計算
        total += wage; //総賃金に加算
    }

    return total;
}

//一般的な賃金
double Standard(int hours) {
    const double hourlyWage = 1072.0; // 時給1072円
    return hourlyWage * hours;
}

int main() {
    int hours;

    //労働時間を入力してもらう
    printf("働いた時間を入力してください: ");
    scanf_s("%d", &hours);

    //各賃金体系に基づいて計算
    double recursiveTotal = Recursive(hours);
    double standardTotal = Standard(hours);

    // 結果を表示
    printf("再帰的な賃金体系での総賃金: %.2f円\n", recursiveTotal);
    printf("一般的な賃金体系での総賃金: %.2f円\n", standardTotal);

    //比較
    if (recursiveTotal > standardTotal) {
        printf("再帰的な賃金体系の方が高い\n");
    }
    else if (recursiveTotal < standardTotal) {
        printf("一般的な賃金体系の方が高い\n");
    }
    else {
        printf("どちらの賃金体系でも同じ\n");
    }

    return 0;
}
