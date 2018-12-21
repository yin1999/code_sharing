//异或就是二进制加法不进位的结果，相同出0，不同出1
//按位异或即可求解 x ^ x = 0, 0 ^ x = x
//当有n个数异或时，只有为奇数次出现的数会对结果产生影响，其余的会因为相互异或而结果为0，任何数与0异结果不变
#include <iostream>
using namespace std;

int main()
{
    double a;
    int t, n, ans = 0;
    cin >> n;
    while (n--)
    {
        cin >> a >> t;
        for (int i = 1; i <= t; i++)
            ans ^= int(a * i);
    }
    cout << ans << endl;
    return 0;
}
