#include <stdio.h>

// ���N���X
class Food {
public:
    virtual void CookSound() const = 0;
};

// �h���N���X Steak
class Steak : public Food {
public:
    void CookSound() const override {
        printf("Sizzle...\n");
    }
};

// �h���N���X Popcorn
class Popcorn : public Food {
public:
    void CookSound() const override {
        printf("Pop! Pop!\n");
    }
};

// �h���N���X Soup
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
        delete foods[i]; // ���������
    }

    return 0;
}
