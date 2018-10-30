#include<iostream>
#include<cmath>
using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

bool prime(int a)   //素数判断
{
	bool flag = true;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a%i == 0)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

void gotbaha(int a_2)
{
	for (int i = 1; i <= a_2/2; i++)     //到a_2/2即可，内循环也会出现这些数的，重复做一边没有意义，输出结果也会重复
	{
		if (!prime(i))      //素数判断，若不是素数，则下一个
			continue;
		for (int j = 1; j < a_2; j++)
		{
			if (!prime(j))
				continue;
			if (i + j == a_2)
				cout << "符合条件的两个素数分别为  " << i << "  " << j << endl;
		}
	}
}

int main()
{
	int n;
	cout << "请输入一个大于等于6的偶数" << endl;
	cout << "输入0则终止本程序" << endl;
	while (cin >> n && n)
	{
		if (n % 2 || n < 6)
			cout << "该数不合法，请重新输入" << endl;
		else
		{
			gotbaha(n);
			cout << "等待再次输入" << endl;
		}
	}
}
