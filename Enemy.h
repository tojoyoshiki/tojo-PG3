#pragma once
#include<stdio.h>

class Enemy {
public:
    void (Enemy::* currentState)();

    Enemy() {
        currentState = &Enemy::Approach;
    }

    void Update() {
        (this->*currentState)();
    }

    void Approach() {
        printf("�G���ڋ�\n");
        currentState = &Enemy::Shoot;
    }

    void Shoot() {
        printf("�G���ˌ�\n");
        currentState = &Enemy::Retreat;
    }

    void Retreat() {
        printf("�G�����E\n");
        currentState = &Enemy::Approach;
    }
};
