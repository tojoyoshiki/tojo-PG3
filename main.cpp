#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//コールバック関数のプロトタイプ宣言
void display_result(int dice_roll, int (*callback)(int));

//奇数か偶数かを判定するコールバック関数
int check_even_or_odd(int num) {
    return num % 2;
}

//3秒カウントダウン関数
void countdown(int seconds) {
    for (int i = seconds; i > 0; i--) {
        printf("%d...\n", i);
        // clock() を使用して1秒待機
        clock_t start_time = clock();
        while (clock() < start_time + CLOCKS_PER_SEC);
    }
    printf("結果発表！\n");
}

int main() {
    int user_choice;
    int dice_roll;

    //シードを設定
    srand(time(NULL));

    // ユーザーに奇数か偶数かを選ばせる
    printf("サイコロを振ります。奇数(半)は0、偶数(丁)は1を入力してください: ");
    scanf_s("%d", &user_choice);

    //サイコロの出目をランダムに生成 (1から6の範囲)
    dice_roll = rand() % 6 + 1;

    //カウント関数呼び出す
    countdown(3);

    //結果表示関数を呼び出し
    display_result(dice_roll, check_even_or_odd);

    //ユーザーの選択と結果を比較
    if (user_choice == check_even_or_odd(dice_roll)) {
        printf("正解です！\n");
    }
    else {
        printf("不正解ですwサイコロの出目は%dでしたwww\n", dice_roll);
    }

    return 0;
}

//コールバック関数を使用して結果を表示
void display_result(int dice_roll, int (*callback)(int)) {
    if (callback(dice_roll) == 0) {
        printf("サイコロの出目は%dで、偶数(丁)です。\n", dice_roll);
    }
    else {
        printf("サイコロの出目は%dで、奇数(半)です。\n", dice_roll);
    }
}
