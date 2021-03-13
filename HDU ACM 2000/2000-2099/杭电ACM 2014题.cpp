#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int temp, sum = 0, max = -1, min = 100000;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			if (max < temp)
			        max = temp;
			else if (min > temp)
				min = temp;
			sum += temp;
		}
    
		sum = sum - max - min;
		cout << fixed << setprecision(2) << sum * 1. / (n - 2) << endl;  //"*1."不可省略！否则会丢失精度；控制精度输出结果
	}
	return 0;
}
