#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int m;
	float a[1000];
	while (cin >> a[0]>> m)
	{
		double sum = a[0];
		for(int i=1;i<m;i++)
		{
			a[i] = sqrt(a[i - 1]);
			sum += a[i];
		}
		cout << fixed << setprecision(2) << sum << endl;   //精度控制输出
	}
	return 0;
}
