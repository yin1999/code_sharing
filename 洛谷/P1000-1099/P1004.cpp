//动态规划
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[10][10];
int f[10][10][10][10];

int max(int a, int b, int c, int d)
{
    int e = max(a, b);
    int f = max(c, d);
    return max(e, f);
}

int main()
{
    cin >> n;
    int xx, yy, aa;
    while(cin >> xx >> yy >> aa && (xx || yy || aa))
    {
        a[xx][yy] = aa;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                for(int l = 1; l <= n; l++)
                {
                    if(i == k && j == l)
                    {
                        f[i][j][k][l] = max(
                            f[i-1][j][k-1][l],
                            f[i-1][j][k][l-1],
                            f[i][j-1][k][l-1],
                            f[i][j-1][k-1][l]
                        )+a[i][j];
                        continue;
                    }

                    f[i][j][k][l] = max(
                        f[i-1][j][k-1][l],
                        f[i-1][j][k][l-1],
                        f[i][j-1][k][l-1],
                        f[i][j-1][k-1][l]
                    )+a[i][j]+a[k][l];
                }
            }
        }
    }
    cout << f[n][n][n][n] << endl;
}
