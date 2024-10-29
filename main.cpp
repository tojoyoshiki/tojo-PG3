#include <stdio.h>

// 基底クラス
class Food {
public:
    virtual void CookSound() const = 0;
};

// 派生クラス Steak
class Steak : public Food {
public:
    void CookSound() const override {
        printf("Sizzle...\n");
    }
};

// 派生クラス Popcorn
class Popcorn : public Food {
public:
    void CookSound() const override {
        printf("Pop! Pop!\n");
    }
};

// 派生クラス Soup
class Soup : public Food {
public:
    void CookSound() const override {
        printf("Bubble bubble...\n");
    }
};

int main() {
    Food* foods[] = { new Steak(), new Popcorn(), new Soup() };

    for (int i = 0; i < 3; ++i) {
        foods[i]->CookSound();
        delete foods[i]; // メモリ解放
    }

    return 0;
}
