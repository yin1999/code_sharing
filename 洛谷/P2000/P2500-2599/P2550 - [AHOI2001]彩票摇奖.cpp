//排好顺序再找有几个数相同（顺序没关系）
#include <iostream>
using namespace std;


void SORT(int *a)
{
	int key, i, j;
	for (i = 0; i < 7; i++)
	{
		key = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (key < a[j])
			{
				a[j + 1] = a[j];
			}
			else
				break;
		}
		a[j + 1] = key;
	}
}

int main()
{
	int n;
	cin >> n;
	int a[7];
	int (*b)[7] = new int[n][7];
	int *ranks = new int[n];
	for (int i = 0; i < 7; i++)
		cin >> a[i];
	SORT(a);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 7; j++)
			cin >> b[i][j];
		SORT(b[i]);
	}
	for (int i = 0; i < n; i++)
	{
		int j = 0, k = 0, count1 = 0;
		while (j != 7 && k != 7)
		{
			if (a[j] > b[i][k])
				k++;
			else if (a[j] < b[i][k])
				j++;
			else
			{
				count1++;
				j++;
				k++;
			}
		}
		ranks[i] = count1;
	}
	for (int i = 7; i > 0; i--)
	{
		int count1 = 0;
		for (int j = 0; j < n; j++)
		{
			if (ranks[j] == i)
				count1++;
		}
		cout << count1 << ' ';
	}
	cout << endl;
	delete[] b;
	delete[] ranks;
	return 0;
}
