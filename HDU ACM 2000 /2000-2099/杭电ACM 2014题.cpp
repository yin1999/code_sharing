#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n, a[100] = { 0 };
	while (cin >> n)
	{
		int temp, sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];    //求总和，最后减去一头一尾即可，可以减少一次循环
		}
    
		for (int i = 0; i < n; i++)   //选择排序，从小到大排（从大到小也可以，对结果不产生影响）
		{
			temp = i;
			for (int j = i; j < n; j++)
			{
				if (a[temp] > a[j])
					temp = j;
			}
			int t = a[i];
			a[i] = a[temp];
			a[temp] = t;
		}
    
		sum = sum - a[0] - a[n - 1];
		cout << fixed << setprecision(2) << sum * 1. / (n - 2) << endl;  //"*1."不可省略！否则会丢失精度；控制精度输出结果
	}
	return 0;
}
