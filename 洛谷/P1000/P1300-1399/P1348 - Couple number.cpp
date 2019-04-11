//根据平方差公式，(a + b) * (a - b)前后两数的奇偶性相同， 所以，一个数可以表示成整数平方差的前提是，它是两个偶数乘积或两个奇数乘积，及为奇数或4的倍数
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int j = 0;
    for (int i = a; i <= b; i++)
    {
        if (i & 1 != 0)
            j++;
        else if (i % 4 == 0)
            j++;
    }
    cout << j << endl;
    return 0;
}
