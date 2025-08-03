#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

bool almost_equal(double a, double b, double eps = 1e-9)
{
    return fabs(a - b) < eps;
}

int main()
{
    double x = 0.1;
    double y = 0.2;
    double z = x + y;

    // 1) 試印出 17 位有效數字
    cout << setprecision(17)
         << "0.1 + 0.2 = " << z << endl;
    // 很可能看到 0.30000000000000004

    // 2) 直接比較相等會失敗
    if (z == 0.3)
        cout << "z == 0.3" << endl;
    else
        cout << "z != 0.3" << endl;

    // 3) 累加誤差：重複小量相加
    double sum = 0.0;
    for (int k = 0; k < 1000000; ++k)
    {
        sum += 0.000001;
    }
    cout << "sum = " << sum
         << "  // 可能不是完全的 1.0" << endl;

    // 4) 取消效應 (Catastrophic Cancellation)
    double big = 1e16 + 1.0;
    double diff = big - 1e16;
    cout << "（1e16+1） - 1e16 = " << diff
         << "  // 可能印出 0.0" << endl;

    return 0;
}
