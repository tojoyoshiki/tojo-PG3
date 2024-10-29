#include <stdio.h>

template <typename T1, typename T2>
class MinComparator {
public:
    T1 value1;
    T2 value2;

    MinComparator(T1 v1, T2 v2) : value1(v1), value2(v2) {}

    auto Min() -> decltype(value1 < value2 ? value1 : value2) {
        return (value1 < value2) ? value1 : value2;
    }
};

int main() {
    //インスタンスを生成
    MinComparator<int, int> comparator1(5, 10);
    MinComparator<int, float> comparator2(5, 3.5f);
    MinComparator<int, double> comparator3(5, 7.2);
    MinComparator<float, int> comparator4(3.5f, 5);
    MinComparator<float, double> comparator5(2.8f, 7.2);
    MinComparator<double, int> comparator6(7.2, 5);

    // Min()メンバ関数を呼び出し
    printf("Min(int, int): %d\n", comparator1.Min());
    printf("Min(int, float): %.2f\n", comparator2.Min());
    printf("Min(int, double): %.2f\n", comparator3.Min());
    printf("Min(float, int): %.2f\n", comparator4.Min());
    printf("Min(float, double): %.2f\n", comparator5.Min());
    printf("Min(double, int): %.2f\n", comparator6.Min());

    return 0;
}