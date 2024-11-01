#pragma once
#include "IShape.h"
#include <stdio.h>

class Rectangle : public IShape {
private:
    double width, height;
    double area;
public:
    //コンストラクタで幅と高さを初期化
    Rectangle(double w, double h) : width(w), height(h), area(0) {}

    //面積を計算
    void Size() override {
        area = width * height;
    }

    //面積を表示
    void Draw() override {
        printf("Rectangle Area: %.2f\n", area);
    }
};
