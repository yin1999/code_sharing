//斐波那契数列相邻两项的值问题
//如何证明请上网搜
//遇到这种问题可以先用枚举算前面的几项，然后，找规律
#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int first = 1, second = 1, sum;
    while (1)
    {
        sum = first + second;
        if (sum > k)
        {
            cout << "m=" << second << endl;
            cout << "n=" << first << endl;
            break;
        }
        second = first;
        first = sum;
    }
    return 0;
}
