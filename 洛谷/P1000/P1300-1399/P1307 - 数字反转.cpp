#include <iostream>
#include <cstring>
using namespace std;

void output(char *str, int mins, int maxs)
{
    for (int i = maxs; i >= mins; i--)
        cout << str[i];
}

int main()
{
    char str[50];    //用字符数组接收数字更好处理
    int i, mins;
    cin >> str;
    if (str[0] == '-')    //若第一位是负号，那么，至少要保留到下标为1的字符
        mins = 1;
    else
        mins = 0;     //否则，只要保留到下标为0的字符
    for (i = strlen(str) - 1; i > mins; i--)    //从个位向高位判断是否为0
    {
        if (str[i] == '0');
        else
            break;
    }
    
    if (mins == 1)    //从低位第一个非零数开始输出
    {
        cout << '-';
        output(str, 1, i);
    }
    else
        output(str, 0, i);
    cout << endl;
    return 0;
}
