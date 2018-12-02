//插入排序加计数，每一条鱼只能看见左边的鱼，要知道左边有几条鱼的数比自己小可以使用暴力求解，也可以用从大到小的插入排序，算交换了几次，就是有几个数比它小
#include<iostream>
using namespace std;


int main()
{
	int a[100], b[100], n, count1, key;
	int i, j;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
	{
		count1 = 0;
		key = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] < key)
			{
				a[j + 1] = a[j];
				count1++;
			}
			else
				break;
		}
		a[j + 1] = key;
		b[i] = count1;
	}
	cout << b[0];
	for (int i = 1; i < n; i++)
		cout << ' ' << b[i];
	cout << endl;
	return 0;
}
