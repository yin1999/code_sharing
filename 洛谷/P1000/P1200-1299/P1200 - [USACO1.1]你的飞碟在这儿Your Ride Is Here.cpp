//此题很简单，不写其它注释了
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[10];
    int length, sum = 1;
    cin >> str;
    length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        sum *= int(str[i] - 'A' + 1);
    }
    int remain1 = sum % 47;
    sum = 1;
    cin >> str;
    length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        sum *= int(str[i] - 'A' + 1);
    }
    int remain2 = sum % 47;
    if (remain1 == remain2)
        cout << "GO" << endl;
    else
        cout << "STAY" << endl;
    return 0;
}
