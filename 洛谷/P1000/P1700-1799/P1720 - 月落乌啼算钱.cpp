//百度一下，斐波那契数列通项公式，也可以代几个数字进去找规律
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    long long f[49] = {0 , 1 , 1};
    int n;
    cin >> n;
    for(int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    cout << fixed << setprecision(2) << f[n] * 1. << endl;
    return 0;
}
