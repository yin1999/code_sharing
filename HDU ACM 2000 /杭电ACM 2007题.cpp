#include<iostream>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n > m)   //将输入数据进行排序，输出结果n<m
		{
			n += m;
			m = n - m;
			n -= m;
		}
		int x = 0, y = 0;
		for (; n <= m; n++)
		{
			if (n & 1)   //位运算判断奇偶性
				y += n * n*n;
			else
				x += n * n;
		}
		cout << x << " " << y << endl;
	}
	return 0;
}
