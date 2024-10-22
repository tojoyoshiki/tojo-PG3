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
        printf("“G‚ªÚ‹ß\n");
        currentState = &Enemy::Shoot;
    }

    void Shoot() {
        printf("“G‚ªËŒ‚\n");
        currentState = &Enemy::Retreat;
    }

    void Retreat() {
        printf("“G‚ª—£’E\n");
        currentState = &Enemy::Approach;
    }
};
