//注意一点，两数不相等，然后暴力运算（可以省略掉一半的运算）
#include <iostream>
using namespace std;

int main()
{
	int s, sum1, sum2;
	cin >> s;
	for (int i = s; ; i++)
	{
		sum1 = 1;
		for (int j = 2; j <= i / 2; j++)   //sum1 = 1 和 到 i / 2省下一半运算
		{
			if (i % j == 0)
				sum1 += j;
		}
		if (sum1 != i)
		{
			sum2 = 1;
			for (int k = 2; k <= sum1 / 2; k++)   //sum2 = 1 和 到sum1 / 2省下一半的运算
			{
				if (sum1 % k == 0)
					sum2 += k;
			}
		}
		else
			continue;
		if (sum2 == i)
		{
			cout << i << ' ' << sum1 << endl;
			break;
		}
	}
	return 0;
}
