#pragma once
class IShape {
public:
    //純粋仮想関数
    virtual void Size() = 0; //面積を計算する関数
    virtual void Draw() = 0; //面積を表示する関数
};

