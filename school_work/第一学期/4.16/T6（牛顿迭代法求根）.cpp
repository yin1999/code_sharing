//牛顿迭代法求根
//https://zh.wikipedia.org/wiki/%E7%89%9B%E9%A1%BF%E6%B3%95
#include<iostream>
using namespace std;

double solve(double x_temp, double y_temp, double deri_temp)   //计算与x轴的交点的横坐标，输入值为函数上的点的横坐标，纵坐标和斜率
{
	double outcome;
	outcome = x_temp + (-1.*y_temp / deri_temp);
	return outcome;
}

double fabs(double temp)    //求实数绝对值，可以选择包含<cmath>来调用库中的同名函数实现这个功能
{
	if (temp < 0)
		return -temp;
	else
		return temp;
}

int main()
{
	int a, b, c, d;
	double x = 1;
	cout << "依次输入3次项，2次项，1次项的系数和常数项" << endl;
	cin >> a >> b >> c >> d;
	while (1)
	{
		double deri = a * 3 * x * x + b * 2 * x + c;    //计算导数值（斜率）
		x = solve(x, a*x*x*x + b * x*x + c * x + d, deri);
		if (fabs(a*x*x*x + b * x*x + c * x + d)<1E-15)   //判断函数上的点的横坐标和与x轴交点的横坐标之差是否小于1E-15，若小于，则break
			break;     //结束循环
	}
	cout << "它的一个解为   " << x << endl;  //输出结果
	return 0;
}
