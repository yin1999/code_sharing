#include <iostream>
#include <algorithm>
using namespace std;

char maze[100][101];     //101!!!不然会输出乱码啊
int n, m;

void Search(int i, int j)
{
	int k, g, count1 = 0;
	for (k = max(i - 1, 0); k < min(i + 2, n); k++)
	{
		for (g = max(j - 1, 0); g < min(j + 2, m); g++)
		{
			if (maze[k][g] == '*')
				count1++;
		}
	}
	maze[i][j] = '0' + count1;
}

int main()
{

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> maze[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maze[i][j] == '?')    //当发现它是问号时，需要判断它周围一圈有几个"*"，并把数量填充进去
			{
				Search(i, j);
			}
		}
		cout << maze[i] << endl;    //输出
	}
	return 0;
}
