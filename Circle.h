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
    //�R���X�g���N�^�Ŕ��a��������
    Circle(double r) : radius(r), area(0) {}

    //�ʐς��v�Z
    void Size() override {
        area = M_PI * radius * radius;
    }

    //�ʐς�\��
    void Draw() override {
        printf("Circle Area: %.2f\n", area);
    }
};

