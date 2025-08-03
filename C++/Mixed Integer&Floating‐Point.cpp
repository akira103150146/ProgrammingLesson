#include <iostream>
using namespace std;

int main()
{
    int i = 3, j = 2;
    double d = 3.0;

    // 1) 純整數除法 → 先計算 3/2 = 1，再轉成 1.0
    double r1 = i / j;

    // 2) 強制轉型到 double → 3.0/2 = 1.5
    double r2 = static_cast<double>(i) / j;

    // 3) 右邊運算元已有 double → 整數自動提升
    double r3 = i / d;

    cout << "i/j       = " << r1 << "  // 整數除法, 再轉型" << endl;
    cout << "double(i)/j = " << r2 << "  // 正確的浮點除法" << endl;
    cout << "i/d       = " << r3 << "  // int→double 自動轉型" << endl;

    return 0;
}
