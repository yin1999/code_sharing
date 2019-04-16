#include <iostream>
using namespace std;

inline int GetLength(int a)
{
    int i = 0;
    if (a == 0)
        return 1;
    if (a < 0)    //注意符号，为负号时长度要加一
        i = 1;
    while (a)
    {
        a /= 10;
        i++;
    }
    return i;
}


struct num
{
    int a, b, ans, len;   //储存第一个数，第二个数，运算结果，长度
    char f;    //储存运算符
};

int main()
{
    int n;
    char c = 0;
    cin >> n;
    num* s = new num[n];
    for (int i = 0; i < n; i++)
    {
        if (!(cin >> s[i].a))   //当输入不正确时，将指针指向错误输入以前，重新输入
        {
            cin.clear();
            cin >> c >> s[i].a;
        }
        cin >> s[i].b;
        if (c == 'a')
        {    
            s[i].ans = s[i].a + s[i].b;
            s[i].f = '+';
        }
        else if (c == 'b')
        {
            s[i].ans = s[i].a - s[i].b;
            s[i].f = '-';
        }
        else
        {
            s[i].ans = s[i].a * s[i].b;
            s[i].f = '*';
        }
        s[i].len = GetLength(s[i].a) + GetLength(s[i].b) + GetLength(s[i].ans) + 2;
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i].a << s[i].f << s[i].b << '=' << s[i].ans << endl;
        cout << s[i].len << endl;
    }
    delete[] s;
    return 0;
}
