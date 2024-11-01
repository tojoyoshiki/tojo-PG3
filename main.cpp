#include <stdio.h>
#include "IShape.h"
#include "Rectangle.h"
#include "Circle.h"

int main() {
    //インスタンス
    Circle circle(5.0); 
    circle.Size();
    circle.Draw(); 

    //Rectangleインスタンス
    Rectangle rectangle(4.0, 6.0); 
    rectangle.Size();
    rectangle.Draw(); 

    return 0;
}