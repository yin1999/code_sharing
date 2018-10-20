#include<iostream>
using namespace std;
int main()
{
	char s1, s2;
	int y, m, d, i, a[12] = { 0,31,28,31,30,31,30,31,31,30,31,30 }, sum;
	while (cin >> y >> s1 >> m >> s2 >> d)
	{
		sum = 0;
		if (((y % 4 == 0) && (y % 100 != 0)) || ((y % 400 == 0)) && (y % 3200 != 0)) //判断闰年
			a[2] = 29;
		else
			a[2] = 28;
		for (i = 0; i < m; i++)
		{
			sum += a[i];
		}
		sum += d;
		cout << sum << endl;
	}
	return 0;
}
