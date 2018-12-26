#include <iostream>
#include <cstdlib>
#include <stack>
#include <iomanip>
using namespace std;

struct point
{
	int x, y;
};

char maze[200][200];
int out[200][200];
int vis[20][20] = { 0 };
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int T = 0, n, m, start_x, start_y, count1 = 0;
bool flag = false;
stack <point> path;

void output()
{
	point temp;
	while (!path.empty())
	{
		temp = path.top();
		path.pop();
		out[temp.x][temp.y] = T--;
	}
	cout << endl << "结果(由起点开始，从一递增表示可行的行进路径):" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (out[i][j] != 0)
				cout << setw(5) << out[i][j];
			else
				cout << setw(5) << 'X';
		}
		cout << endl;
	}
}

void dfs(int x, int y)
{
	T++;
	for (int i = 0; i < 4; i++)
	{
		point p;
		p.x = x + dir[i][0];
		p.y = y + dir[i][1];
		if (p.x >= 0 && p.x < n && p.y >= 0 && p.y < m && vis[p.x][p.y] == 0 && maze[p.x][p.y] == '.')
		{
			vis[p.x][p.y] = 1;
			path.push(p);
			if (T == count1)
			{
				output();
				flag = true;
				return;
			}
			dfs(p.x, p.y);
			if (flag == true)
				return;
			path.pop();
			vis[p.x][p.y] = 0;
		}
	}
	T--;
}
int main()
{
	cout << "请输入地图的高和宽。" << endl;
	cin >> n >> m;
	cout << "请输入地图 's' or 'S'为起点， '.'为可经点， 其它字母为封锁点(不能走)。" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 's' || maze[i][j] == 'S')
			{
				start_x = i;
				start_y = j;
			}
			else if (maze[i][j] == '.')
				count1++;
		}
	}
	vis[start_x][start_y] = 1;
	dfs(start_x, start_y);
	system("pause");
	return 0;
}
