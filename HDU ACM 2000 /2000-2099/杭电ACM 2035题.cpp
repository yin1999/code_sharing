#include<iostream>
using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
			break;
		int sum = 1;
		a = a % 1000;    //结果为幂的最后三位，其取值也只与被乘数的最后三位
		for (int i = 0; i < b; i++)
		{
			sum *= a;
			sum = sum % 1000;   //防止内存溢出，运算过慢，同时符合结果要求
		}
		cout << sum << endl;
	}
	return 0;
}
