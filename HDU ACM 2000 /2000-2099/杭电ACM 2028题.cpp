#include<iostream>
using namespace std;

int factor(int a, int b)  //辗转相除法求最大公因数
{
	int c = a % b;
	while (c)
	{
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int temp, sum;
		cin >> temp;
		sum = temp;
    
		for (int i = 0; i < n - 1; i++)
		{
			cin >> temp;
			sum = sum / factor(temp, sum) * temp;   //题目有坑，最终输出的结果在32位整数里面，先乘再除就有可能超范围
		}
    
		cout << sum << endl;
	}
	return 0;
}
