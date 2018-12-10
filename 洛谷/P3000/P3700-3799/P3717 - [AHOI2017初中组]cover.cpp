#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n, m, r, sum = 0, x, y;
	int maze[100][100] = { 0 };
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--;  //不要忘记减一
		y--;
		for (int j = max(y - r, 0); j <= min(y + r, n - 1); j++) //减一！
		{
			for (int k = max(x - r, 0); k <= min(x + r, n - 1); k++)
			{
				if (sqrt(double((y - j) * (y - j) + (x - k) * (x - k))) <= r && maze[j][k] == 0)
				{
					sum++;
					maze[j][k] = 1;
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}
