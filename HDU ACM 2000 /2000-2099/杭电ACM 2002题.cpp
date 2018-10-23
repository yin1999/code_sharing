#include<iostream>
#include<cmath>
#include<iomanip>
#define PI 3.1415927
using namespace std;

int main()
{
	double r;     //定义半径r为double型，测试使用float类型会输出“错误的答案”
	while (cin >> r)
	{
		cout << fixed << setprecision(3) << 4. / 3 * PI*r*r*r << endl;     //注意4.==>4.0
	}
}
