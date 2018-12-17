#include<iostream>
using namespace std;

long long m, n, k, ans = 0;

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            ans += i * j;   //所有矩形（包括正方形）
        }
    for (int i = 0;; i++)
    {
        if (i > n || i > m)
            break;
        k += (n - i) * (m - i);   //正方形
    }
    cout << k << " " << ans - k << endl;
    return 0;
}
