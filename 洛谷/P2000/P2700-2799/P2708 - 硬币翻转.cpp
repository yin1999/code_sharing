//题意，每次翻硬币只能同时翻1到n个，所以，当后一个与前面不一样时，就要翻面
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[200];
    int count1 = 0;
    char temp;
    cin >> str;
    int length = strlen(str);
    for (int i = 1; i < length; i++)
    {
        if (str[i - 1] != str[i])
            count1++;
    }
    if (str[length - 1] == '0')
        count1++;
    cout << count1 << endl;
    return 0;
}
