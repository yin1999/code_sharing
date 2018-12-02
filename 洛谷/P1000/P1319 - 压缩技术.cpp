//开辟一个输入数据量的空间来储存数据
#include<iostream>
using namespace std;


int main()
{
	int n, count1 = 0, count2 = 0, temp;   //输入行列数，数组下标，是1还是0
	cin >> n;
	int * a = new int[n * n + 10];
	while (cin >> temp)
	{
		while (temp--)
		{
			a[count1++] = count2;
		}
		count2 = 1 - count2;
	}
	count1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[count1++];
		cout << endl;
	}
	delete[] a;
	return 0;
}
