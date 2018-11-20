#include<iostream>
using namespace std;

char maze[7][7];
bool flag;
int vis[7][7];
int n, m, T;
int start_x, start_y;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		T--;
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m&& T>=0 && vis[ny][nx]==0)
		{
			if (maze[ny][nx] == 'D'&&T == 0)
			{
				cout << "YES" << endl;
				flag = true;
				return;
			}
			else if (maze[ny][nx] == '.')
			{
				vis[ny][nx] = 1;
				dfs(nx, ny);
				vis[ny][nx] = 0;
			}
		}
		T++;
		if (flag || T <= 0)
			return;
	}
}
int main()
{
	while (cin >> n >> m >> T)
	{
		if (n == 0 && m == 0 && T == 0)
			return 0;
		flag = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> maze[i][j];
				if (maze[i][j] == 'S')
				{
					start_y = i;
					start_x = j;
				}
				vis[i][j] = 0;
			}
		}
		vis[start_y][start_x] = 1;
		dfs(start_x, start_y);
		if (!flag)
			cout << "NO" << endl;
	}
}
