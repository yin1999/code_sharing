#include <iostream>
using namespace std;

int maze[1000][1000];

int sumup(int row, int col, int n)  //统计所在位置能消灭的敌人数
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += maze[row][i] + maze[i][col];
	}
	return sum;
}

int main()
{
	int n, max = 0, temp;
	bool flag = false;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		cin >> maze[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maze[i][j] == 0)
			{
				flag = true;
				temp = sumup(i, j, n);
				if (temp > max)
					max = temp;
				if (max == 2 * n - 2)   //不可能比这个值更大，直接输出并终止程序
				{
					cout << max << endl;
					return 0;
				}
			}
		}
	}
	if (flag == false)
		cout << "Bad Game!" << endl;
	else
		cout << max << endl;
	return 0;
}
