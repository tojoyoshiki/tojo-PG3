#pragma once
#include "IShape.h"
#include <stdio.h>

class Rectangle : public IShape {
private:
    double width, height;
    double area;
public:
    //�R���X�g���N�^�ŕ��ƍ�����������
    Rectangle(double w, double h) : width(w), height(h), area(0) {}

    //�ʐς��v�Z
    void Size() override {
        area = width * height;
    }

    //�ʐς�\��
    void Draw() override {
        printf("Rectangle Area: %.2f\n", area);
    }
};
