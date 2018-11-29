#include<iostream>
using namespace std;

void sort1(int &a, int &b)
{
    if(a < b)
    {
        int t = b;
        b = a;
        a = t;
    }
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    sort1(b, c);
    sort1(a, b);
    sort1(b, c);
    int max1 = a;
    int min1 = c;
    while(max1 != min1)  //辗转相减法求最大公约数
    {
	    if(max1 > min1)
	    {
		    max1 -= min1;
	    }
	    else
	    {
		    min1 -= max1;
	    }
    }
    cout << c / max1 << "/" << a / min1 << endl;
    return 0;
}
