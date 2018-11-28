//这个算法对于计算机来说，运算很快
#include<iostream>
using namespace std;

int main()
{
	int n, x;
	long long sum = 0;
	cout << "请输入x的值，然后是从高次到低次的系数" << endl;
	cin >> x;
	while (cin >> n)
	{
		sum = n + x * sum;
	}
	cout << "结果是" << endl;
	cout << sum << endl;
	return 
}
