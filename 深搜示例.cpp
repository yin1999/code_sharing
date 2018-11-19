#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;

int maze[10][10];//迷宫
int vis[10][10];//记录迷宫中的某个位置是否访问过
int n, m;
int count1;//路径条数
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };//四个方向

struct point//位置
{
	int x, y;
} p;

stack<point> path, temp;//记录路径,temp是一个临时变量，和path一起处理路径



void dfs(int x, int y)//x,y:当前位置
{
	if (x == n - 1 && y == m - 1)//成功---下面处理路径问题
	{
		cout << "******************路径" << ++count1 << "******************" << endl;
		while (!path.empty())//将path里面的点取出来，放在temp里面
		{//path从栈顶-栈底的方向，路径是从终点-起点的顺序
			point p1 = path.top();
			path.pop();
			temp.push(p1);
		}
		while (!temp.empty())
		{//输出temp里面的路径，这样刚好是从起点到终点的顺序
			point p1 = temp.top();
			temp.pop();
			path.push(p1);//将路径放回path里面，因为后面还要回溯!!!
			cout << "(" << p1.x << "," << p1.y << ")" << endl;
		}
		return;
	}

	if (x < 0 || x >= n || y < 0 || y >= m)//越界
		return;

	//如果到了这一步，说明还没有成功，没有出界
	for (int i = 0; i < 4; i++)//从4个方向探测
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];//nx,ny：选择一个方向，前进一步之后，新的坐标
		if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] == 0 && vis[nx][ny] == 0)
		{//条件：nx,ny没有出界，maze[nx][ny]=0这个点不是障碍可以走，vis[nx][ny]=0说明(nx,ny)没有访问过，可以访问

			vis[nx][ny] = 1;//设为访问过
			p.x = nx;
			p.y = ny;
			path.push(p);//让当前点进栈

			dfs(nx, ny);//进一步探测

			vis[nx][ny] = 0;//回溯
			path.pop();//由于是回溯，所以当前点属于退回去的点，需要出栈
		}
	}
}

int main()
{
	count1 = 0;
	if(!freopen("in.txt", "r", stdin));//读取.cpp文件同目录下的名为in.txt的文件
		return -1;
	
	p.x = 0;
	p.y = 0;
	path.push(p);//起点先入栈

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			vis[i][j] = 0;
			cin >> maze[i][j];
		}
	}
	dfs(0, 0);

	return 0;
}

/*
in.txt文件内容
5 6
0 1 0 0 0 1
0 0 0 1 0 0
1 0 1 0 0 1
1 0 0 1 0 1
1 1 0 0 0 0
*/
