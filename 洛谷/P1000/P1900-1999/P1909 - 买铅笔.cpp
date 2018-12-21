#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0x7fffffff, temp, num, price;   //sum初始化为int型最大值（16进制表示）
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        cin >> num >> price;
        if (n % num == 0)
            temp = n / num * price;
        else
            temp = (n / num + 1) * price;
        if (temp < sum)
            sum = temp;
    }
    cout << sum << endl;
    return 0;
}
