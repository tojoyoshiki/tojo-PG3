#include <stdio.h>
#include "IShape.h"
#include "Rectangle.h"
#include "Circle.h"

int main() {
    //�C���X�^���X
    Circle circle(5.0); 
    circle.Size();
    circle.Draw(); 

    //Rectangle�C���X�^���X
    Rectangle rectangle(4.0, 6.0); 
    rectangle.Size();
    rectangle.Draw(); 

    return 0;
}