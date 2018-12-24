//当边长为n时，长度为1的一共有n段， 长度为2的一共有n - 1段，下面求正方形个数即用了这个规律
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n < m)
        swap(n, m);   //保证n为较小数
        
    int sum = 0;            //求正方形总个数
    for (int i = 0; i < n; i++)
        sum += (n - i) * (m - i);
        
    int all = (n + 1) * n / 2 * (m + 1) * m / 2;    //长方形总个数（包括特殊的长方形——正方形）  高斯求和公式
    
    cout << sum << ' ' << all - sum << endl;   //输出
    return 0;
}
