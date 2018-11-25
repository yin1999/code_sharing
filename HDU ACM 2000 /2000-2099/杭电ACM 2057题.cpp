#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    __int64 a, b, c;
    while(cin >> hex >> a >> b)    //直接输入16进制数
    {
        c = a + b;
        if(c < 0)    //负数使用补码，直接输出会出错
        {
            cout<< '-';
            c = -c;
        }
        cout << setiosflags(ios::uppercase) << hex << c << endl;
    }
    return 0;
}
