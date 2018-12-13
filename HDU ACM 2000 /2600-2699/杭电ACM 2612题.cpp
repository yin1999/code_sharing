//两次广度优先搜索求解
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

struct node
{
	int x, y, step;
};

int n, m;
char ch[209][209];
int dir[4][2] = { 0, -1, -1, 0, 0, 1, 1, 0 };
int vis[209][209], num[209][209];

bool is_ok(node a)
{
	return a.x >= 0 && a.x < n && a.y >= 0 && a.y < m;
}

void bfs(int x,  int y)
{
	node s, t, ne;
	int i;
	s.x = x;
	s.y = y;
	s.step = 0;
	queue <node> q;
	while (!q.empty())
		q.pop();
	vis[x][y] = 1;
	q.push(s);
	while (!q.empty())
	{
		t = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			ne.x = t.x +dir[i][0];
			ne.y = t.y + dir[i][1];
			ne.step = t.step + 1;
			if (is_ok(ne) && ch[ne.x][ne.y] != '#' && !vis[ne.x][ne.y])
			{
				vis[ne.x][ne.y] = 1;
				q.push(ne);
				if (ch[ne.x][ne.y] == '@')
				{
					num[ne.x][ne.y] += ne.step;
				}
			}
		}
	}
}

int main()
{
	int yx, yy, mx, my, i, j;
	while (cin >> n >> m)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cin >> ch[i][j];
				if (ch[i][j] == 'Y')
				{
					yx = i;
					yy = j;
				}
				else if (ch[i][j] == 'M')
				{
					mx = i;
					my = j;
				}
			}
		}
		memset(vis, 0, sizeof(vis));
		memset(num, 0, sizeof(num));
		bfs(yx, yy);
		memset(vis, 0, sizeof(vis));
		bfs(mx, my);
		int ans = 0xffffff;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (num[i][j] != 0 && ans > num[i][j])
					ans = num[i][j];
			}
		}
		cout << ans * 11 << endl;
	}
	return 0;
}
