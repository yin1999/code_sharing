#include<iostream>
using namespace std;

long long fac(int n)
{
	long long temp = 1;
	while (n)
	{
		temp *= n;
		n--;
	}
	return temp;
}
int main()
{
	int a, b, c;
	cout << "请输入三个数，以计算它们的阶乘和" << endl;
	cout << "输入三个0则终止本程序" << endl;
	while (cin >> a >> b >> c)
	{
		long long sum;
		sum = fac(a) + fac(b) + fac(c);
		cout << "结果为  " << sum << endl << "等待再次输入" << endl;
	}
	return 0;
}
