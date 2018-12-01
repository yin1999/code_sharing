//动规问题，01背包，把每一个砝码看成独立的一个物品，放到背包中，算出一共有集中情况
#include<iostream>
using namespace std;

int main()
{
	int a[6], b[6] = { 1, 2, 3, 5, 10, 20 };
	int sum = 0, total = 0;
	bool flag[1001] = { true };
	for (int i = 0; i < 6; i++)
	{
		cin >> a[i];
		sum += a[i] * b[i];   //计算出最大可能的值，减少后面不必要的循环次数
	}
	for (int i = 0; i < 6; i++)
	{
		while (a[i]--)
		{
			for (int j = sum; j >= b[i]; j--)
				flag[j] = flag[j] || flag[j - b[i]];
		}
	}
	for (int i = 1; i <= sum; i++)
		total += (int)flag[i];
	cout << "Total=" << total << endl;
	return 0;
}
