#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		int a_fac[10000],b_fac[10000];  //储存因数
		int a_count = 0, b_count = 0;  //给因数计数
		for (int i = 1; i <= a / 2; i++)
		{
			if (a%i == 0)
				a_fac[a_count++] = i;   //若为因数，则储存到数组中
		}
		int sum = 0;
		for (int i = 0; i < a_count; i++)   //求因数和
			sum += a_fac[i];
		if (b != sum)   //判断是否满足前一个条件，若不满足，直接输出"NO"并跳出循环
		{
			cout << "NO" << endl;
			continue;
		}
    
		for (int i = 1; i <= b / 2; i++)
		{
			if (b%i == 0)
				b_fac[b_count++] = i;
		}
		sum = 0;
		for (int i = 0; i < b_count; i++)
			sum += b_fac[i];
		if (a = sum)
			cout << "YES" << endl;
    else
      cout<< "NO" << endl;
	}
	return 0;
}
