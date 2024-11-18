#include <stdio.h>
#include <cstdio>
#include <list>
#include <cstring>

// 駅名を保持するための文字列最大長を定義
constexpr int MAX_NAME_LENGTH = 50;

int main() {
    // 1970年山手線駅名一覧を初期化
    const char* stationNames1970[] = {
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani",
        "Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro",
        "Mejiro", "Takadanobaba", "ShinOkubo", "Shinjuku", "Yoyogi",
        "Harajuku", "Shibuya", "Ebisu", "Meguro", "Gotanda", "Osaki",
        "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"
    };

    // 双方向リスト
    std::list<const char*> stations(stationNames1970, stationNames1970 + 28);

    //西日暮里駅1971に追加
    auto it = stations.begin();
    while (std::strcmp(*it, "Nippori") != 0) ++it;
    stations.insert(it, "NishiNippori");

    // 2019年の状態
    printf("2019 yamanotesen:\n");
    for (const char* station : stations) {
        printf("%s\n", station);
    }
    printf("\n");

    //高輪ゲートウェイ駅を2020のとこについか
    it = stations.begin();
    while (std::strcmp(*it, "Shinagawa") != 0) ++it;
    stations.insert(std::next(it), "Takanawa Gateway");

    // 2022年の状態
    printf("2022 yamanotesen:\n");
    for (const char* station : stations) {
        printf("%s\n", station);
    }

    return 0;
}
