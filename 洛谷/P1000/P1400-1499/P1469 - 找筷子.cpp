//同P1161 - 开灯
//按位异或处理 x ^ x =0, x ^ 0 = x， 满足交换律
#include <iostream>
using namespace std;

int main()
{
    int n, length, ans = 0;
    cin >> n;
    while (n--)
    {
        cin >> length;
        ans ^= length;
    }
    cout << ans << endl;
    return 0;
}
