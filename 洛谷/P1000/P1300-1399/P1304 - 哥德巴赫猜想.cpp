//一个大于等于4的偶数可以被拆成两个素数的和
#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int t)
{
    int s = sqrt(t);
    for (int i = 2; i <= s; i++)
    {
        if (t % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int j = 4; j <= n; j += 2)
    {
        if (isprime(j - 2))
            cout << j << '=' << 2 << '+' << j - 2 << endl;
        else
        {
            for (int i = 3; i < j; i += 2)
            {
                if (isprime(i) && isprime(j - i))
                {
                    cout << j << '=' << i << '+' << j - i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
