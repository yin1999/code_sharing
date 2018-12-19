//快速排序算法 数组限制为10001个，且为整型（大小限制0-10000）
//以“-1”为停止本次输入标志
#include<iostream>
using namespace std;

int main()
{
	
	while (1)
	{
		int num[10001] = { 0 };
		int N, i = 1;
		while (cin >> N && N != -1)
		{
			num[N] += 1;
			i++;
		}
		for (int j = 0, k = 1; k <= i;)
		{
			if (num[j] != 0)
			{
				cout << j << " ";
				num[j] -= 1;
				k++;
			}
			else
				j++;
		}
	}
}
