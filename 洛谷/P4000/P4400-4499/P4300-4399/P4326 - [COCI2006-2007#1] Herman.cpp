//曼哈顿距离把圆变成了一个正方形，四个等腰直角三角形拼接，PI的精度高一点（不用那么长，double没那么高的精度，PI是网上复制的）
#include<iostream>
#include<iomanip>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954
using namespace std;


int main()
{
    int R;
    cin >> R;
    cout << fixed << setprecision(6) << R * R * PI << endl;
    cout << fixed << setprecision(6) << R * R * 2. << endl;
    return 0;
}
