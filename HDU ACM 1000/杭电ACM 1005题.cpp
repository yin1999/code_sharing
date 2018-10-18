/*由题目的式子可知因为f[n]是%7后得出的结果，而%7后有7种结果0，1，2，3，4，5，6;所以结果总共有7*7种两个f有49种不同的取法
（假使输出结果算是不一样的，实则只有7种）。所以，只要给输入的数组数取余就OK了*/
#include<iostream>
using namespace std;

int main()
{
	int a, b, n;
	int f[50];
	while (cin >> a >> b >> n)     //输入a，b和数组数
	{
		if (a == 0 && b == 0 && n == 0)break;

		if (n == 1 || n == 2)
		{
			cout << "1" << endl;
			continue;
		}
		f[1] = 1; f[2] = 1;
		for (int i = 3; i <= n % 49; i++)
		{
			f[i] = (a*f[i - 1] + b * f[i - 2]) % 7;

		}
		cout << f[n % 49] << endl;
	}
	return 0;
}
