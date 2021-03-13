#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n, m;
	while (cin >> m)
	{
		
    for (int i = 1; i <= m; i++)
		{
			double sum = 0;
			cin >> n;
			
      for (int j = 1; j <= n; j++)
			{
				if (j & 1)
					sum += 1. / j;
				else
					sum -= 1. / j;
			}
      
			cout << fixed << setprecision(2) << sum << endl;   //控制精度输出结果，注意格式
		}
	}
	return 0;
}
