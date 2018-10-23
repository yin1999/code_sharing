#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n, a[100] = { 0 };
	while (cin >> n)
	{
		int temp, sum = 0, max = 1000000, min = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			
			sum += temp;
		}
    
		sum = sum - max - min;
		cout << fixed << setprecision(2) << sum * 1. / (n - 2) << endl;  //"*1."不可省略！否则会丢失精度；控制精度输出结果
	}
	return 0;
}
