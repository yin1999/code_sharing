//可以参考https://github.com/yin1999/code_sharing/tree/master/ESTA/2018.11%E7%8E%B0%E5%9C%BA%E7%BC%96%E7%A8%8B%E5%A4%A7%E8%B5%9B/%E9%97%AE%E9%A2%98D-%E6%80%BB%E5%92%8C%E9%97%AE%E9%A2%98
#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int n, m;

	while (cin >> n >> m)
	{
		if (n == 0 & m == 0)
			return 0;
		int a;
		for (int i = (int)sqrt(2 * m); i >= 1; i--)
		{
			a = a = (m - ((i - 1)*i) / 2) / i;
			if (m == a * i + (i*(i - 1)) / 2 && a > 0)
				if (a + i - 1 <= n)
					cout << "[" << a << "," << a + i - 1 << "]" << endl;
		}
		cout << endl;
	}
	return 0;
}
