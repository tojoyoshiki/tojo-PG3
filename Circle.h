#pragma once
#include "IShape.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

class Circle : public IShape {
private:
    double radius;
    double area;
public:
    //コンストラクタで半径を初期化
    Circle(double r) : radius(r), area(0) {}

    //面積を計算
    void Size() override {
        area = M_PI * radius * radius;
    }

    //面積を表示
    void Draw() override {
        printf("Circle Area: %.2f\n", area);
    }
};

