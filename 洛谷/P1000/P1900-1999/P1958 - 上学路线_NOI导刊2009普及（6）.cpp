#include <iostream>
using namespace std;

int a, b, n, ans = 0;
int maze[17][17] = { 0 };
int dir[2][2] = { { 1, 0 }, { 0, 1 } };

void dfs(int x, int y)
{
	for (int i = 0; i < 2; i++)
	{
		int t_x = x + dir[i][0];
		int t_y = y + dir[i][1];
		if (t_x == a && t_y == b)
			ans++;
		else if (t_x <= a && t_y <= b && maze[t_x][t_y] == 0)
		{
			dfs(t_x, t_y);
		}
	}
}

int main()
{
	cin >> a >> b >> n;
	int t_x, t_y;
	for (int i = 0; i < n; i++)
	{
		cin >> t_x >> t_y;
		maze[t_x][t_y] = 1;
	}
	dfs(1, 1);
	cout << ans << endl;
	return 0;
}
