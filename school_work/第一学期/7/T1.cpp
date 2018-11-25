#include<iostream>
#include<cmath>
using namespace std;

struct date
{
    int y;
    int m;
    int d;
};

int judge(int year)
{
    if(year&3 == 0 && year%100 != 0 || year%400 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    date a;
    int sum;
    int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    while(cin >> a.y >> a.m >> a.d)
    {
        a.m = abs(a.m);
        a.d = abs(a.d);
        sum = a.d;
        if(a.m < 2)
            sum += judge(a.y);

        for(int i = 0; i < a.m - 1; i++)
            sum += month[i];

        cout << "今天是" << a.y << "年的第" << sum << "天" << endl;
    }
    return 0;
}
