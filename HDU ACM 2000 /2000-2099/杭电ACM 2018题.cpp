#include<iostream>
using namespace std;


int main()
{
	int n;
	while (cin >> n && n)
	{
		int a[3] = { 0,0,1 };     //a[0]表示刚出生的牛的数量，a[2]表示成年的牛的数量
		for (int i = 2; i <= n; i++)    //根据题意（示例），第一年没有小牛出生
		{
			int temp = a[2];
			a[2] += a[1];
			a[1] = a[0];
			a[0] = temp;
		}
		cout << a[0] + a[1] + a[2] << endl;
	}
	return 0;
}
