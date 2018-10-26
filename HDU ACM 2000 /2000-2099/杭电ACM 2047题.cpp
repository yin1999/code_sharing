//使用递归算出每一组的可能性，算法十分巧妙，使用组合数算最后几个会超出范围，不建议使用（大数相乘可以实现，但十分耗时）
//此题使用了规律而已。。。。
#include<iostream>
using namespace std;

int main()
{
    long long int a[40];
    a[0] = 3;
    a[1] = 8;
    int N;
    for (int i = 2; i < 40; i++)
        a[i] = 2 * (a[i - 1] + a[i - 2]);
    while (cin >> N)
    {
            cout << a[N - 1] << endl;
    }
}
