//动态规划，完全背包问题，从小到大算（一个东西可以取多次）
#include<iostream>
#include<algorithm>
using namespace std;

int point[10001] = {0};

int main()
{
    int m, n, t, p;
    cin >> m >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> p >> t;
            for(int j = t; j <= m; j++)
                point[j] = max(point[j], point[j - t] + p);
    }
    cout << point[m] << endl;
    return 0;
}
