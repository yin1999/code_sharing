#include<iostream>
using namespace std;

void gcb(int &c, int &d)   //辗转相减法求最大公因数，并通分
{
    int a = c, b = d;
    while(a != b)
    {
        if(a > b)
            a -= b;
        else
            b -= a;
    }
    c /= a;
    d /= a;
}

int main()
{
    int a, b, c, d;
    char temp;
    cin >> a >> temp >> b >> c >> temp >> d;
    gcb(a, b);
    gcb(c, d);
    gcb(a, d);
    gcb(b, c);
    cout<< b * d << " " << a * c << endl;    //输出结果是“列 行”，其它没有了
    return 0;
}
