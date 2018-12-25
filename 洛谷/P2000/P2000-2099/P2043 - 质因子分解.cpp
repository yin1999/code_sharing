#include <iostream>
#include <cmath>
using namespace std;

int num[10001] = { 0 };

int main()
{
    int n, i, j;
    cin >> n;
    for (i = 2; i <= n; i++)    //遍历n!中的所有数
    {
        int t = i;
        while ((t & 1) == 0)   能否被2整除（唯一的偶数质数）
        {
            num[2]++;
            t >>= 1;
        }
        
        for (j = 3; j <= t; j += 2)  //奇数（不用判断是否为质数，当它不是质数时，该数肯定不能被它乘除）
        {
            while (t % j == 0)
            {
                num[j]++;
                t /= j;
            }
        }
        
    }
    for (i = 2; i <= n; i++)
    {
        if (num[i])
            cout << i << ' ' << num[i] << endl;
    }
    return 0;
}
