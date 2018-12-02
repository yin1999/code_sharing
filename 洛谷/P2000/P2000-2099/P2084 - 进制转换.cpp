#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n;
    bool flag = false;
    char str[1001];
    cin >> n >> str;
    int length = strlen(str);
    for(int i = 0; i < length; i++)
    {
        if(str[i] != '0')
        {
            if(flag)    //判断前面是否有数被输出，如果有，输出+号
                cout << '+';
            else
                flag = true;    //如果没有，则标记成前面有数输出，下一行输出了此情况下的第一个数据
            cout << str[i] << '*' << n << '^' << length - 1 - i;
        }
    }
    cout << endl;
    return 0;
}
