//加减法，自右向左处理，挺方便的，自左向右需要先储存前面出现的符号，也是比较简单的
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[60001];
    long long sum = 0;
    int temp = 0;
    int bits = 1;
    cin >> str;
    int length = strlen(str);
    for (int i = length - 1; i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            temp += int(str[i] - '0') * bits;
            bits *= 10;
        }
        else if (str[i] == '+')
        {
            sum += temp;
            temp = 0;
            bits = 1;
        }
        else
        {
            sum -= temp;
            temp = 0;
            bits = 1;
        }
    }
    if (temp != 0)
        sum += temp;
    cout << sum << endl;
    return 0;
}
