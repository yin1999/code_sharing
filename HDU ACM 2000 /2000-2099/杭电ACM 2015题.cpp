#include<iostream>
#include<iomanip>
using namespace std;


bool outcome(bool a, int addup, int c)    //定义输出函数，若产生输出，则返回false，标记是否需要输出空格
{
	if (a)    //若为第一次输出，则不输出空格
	{
		cout << addup / c;
		a = false;
	}
	else     //非第一次输出，输出空格
		cout << " " << addup / c;
    return a;
}

int main()
{
  int n, m, temp, sum, num;
  bool flag;
	while (cin >> n >> m)
	{
		flag = true;
		num = 2;
		for (; n > 0; n -= m)
		{
			sum = 0;
			if (n >= m)
			{
				for (int i = 1; i <= m; i++)
				{
					sum += num;
					num += 2;
				}
				flag = outcome(flag, sum, m);
			}
			else
			{
				for (int i = 1; i <= n; i++)
				{
					sum += num;
					num += 2;
				}
				flag = outcome(flag, sum, n);
			}
		}
		cout << endl;
	}
	return 0;
}
