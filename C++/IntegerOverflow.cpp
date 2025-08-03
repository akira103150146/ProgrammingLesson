#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // 有號整數溢位：未定義行為 (undefined behavior)
    int a = INT_MAX; //  2147483647
    cout << "a = " << a << endl;
    a = a + 1;
    cout << "a + 1 = " << a << "  // 溢位後可能變成負數" << endl;

    // 無號整數 (unsigned) 會模 2^32 包回
    unsigned int b = UINT_MAX; //  4294967295
    cout << "b = " << b << endl;
    b = b + 1;
    cout << "b + 1 = " << b << "  // 包回到 0" << endl;

    // 小型整數溢位：char 只 1 byte
    signed char c = 127;
    cout << "c = " << int(c) << endl;
    c = c + 1;
    cout << "c + 1 = " << int(c)
         << "  // 由 127 變成 -128" << endl;

    return 0;
}
