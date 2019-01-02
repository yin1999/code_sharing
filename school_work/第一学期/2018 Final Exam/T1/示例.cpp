#include <iostream>
using namespace std;

void find(int (*a)[4], int n)     // 1
{
	int i, j, k, max, maxj, flag = 0;
	for (i = 0; i < n; i++)
	{
		max = a[i][0];
		maxj = 0;
		for (j = 1; j < 4; j++)
		{
			if (a[i][j] > max)     // 2
			{
				max = a[i][j];
				maxj = j;
			}
		}
		for (k = 0; k < n; k++)
			if (max > a[k][maxj])
				break;                 // 3
		if (k >= n)
		{
			cout << "a[" << i << "][" << maxj << "]=" << max << endl;
			flag = 1;
		}
	}
	if (flag != 1)        // 4
		cout << "No!\n";
}

int main()
{
	int a[3][4] = { {1, 2, 3, 4,}, {4, 5, 5, 6}, {3, 5, 6, 7} };
	find(a, 3);
	return 0;
}
