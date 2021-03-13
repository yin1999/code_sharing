//使用选择排找出最小值
#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n && n)
	{
		int temp = 0, a[100];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] < a[temp])
				temp = i;
		}
		int t = a[0];
		a[0] = a[temp];
		a[temp] = t;
		cout << a[0];
		for (int i = 1; i < n; i++)
			cout << " " << a[i];
		cout << endl;
	}
	return 0;
}
