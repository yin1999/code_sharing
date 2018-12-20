#include <iostream>
using namespace std;

int getnum(int temp, int x)  //计算一个数中有多少个x
{
    int count1 = 0;
    while (temp)
    {
        if (temp % 10 == x)
            count1++;
        temp /= 10;
    }
    return count1;
}

int main()
{
    int n, x, sum = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        sum += getnum(i, x);
    }
    cout << sum << endl;
    return 0;
}
