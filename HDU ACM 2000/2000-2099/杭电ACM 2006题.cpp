#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 1;
		for (int i = 1; i <= n; i++)
		{
			int temp;
			cin >> temp;
			if (temp & 1)    //判断是否为奇数（位运算：一位为1时，输出1,为true，一位为0时，输出0，为false）
				sum *= temp;
		}
		cout << sum << endl;
	}
	return 0;
}
