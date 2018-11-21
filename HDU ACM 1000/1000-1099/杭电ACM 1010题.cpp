#include<iostream>
using namespace std;

char maze[7][7];     //记录迷宫中的各种点
bool flag;   //记录是否找到一条可行路径
int vis[7][7];    //记录点是否已经走过
int n, m, T;    //分别记录行数，列数和可走步数
int start_x, start_y;   //记录起始点位置（x代表列，y代表行！）
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };   //记录4种方向

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0];   //选择一个方向进行搜索
		int ny = y + dir[i][1];
    
		T--;   //步数-1
		if (nx >= 0 && nx < m&&ny >= 0 && ny < n&& T>=0 && vis[ny][nx]==0)
		{
			if (maze[ny][nx] == 'D'&&T == 0)   //找到一条合适路径
			{
				cout << "YES" << endl;
				flag = true;    //标记为找到
				return;
			}
      
			else if (maze[ny][nx] == '.')
			{
				vis[ny][nx] = 1;    //将该点标记为走过
        
				dfs(nx, ny);
        
				vis[ny][nx] = 0;    //回溯
			}
		}
		T++;    //回溯
		if (flag || T <= 0)
			return;   //若可走步数小于等于0，说明无法再继续走下去了，终止循环
	}
}


int main()
{
	while (cin >> n >> m >> T)
	{
  
		if (n == 0 && m == 0 && T == 0)  //是否结束循环判断
			return 0;
      
		flag = false;   //初始化为false
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> maze[i][j];   //记录点的类型
				if (maze[i][j] == 'S')   //若为起点，则将起点坐标存至 start_x,start_y种
				{
					start_y = i;
					start_x = j;
				}
				vis[i][j] = 0;   //初始化为0，标记为没走过这个点
			}
      
		}
		vis[start_y][start_x] = 1;    //不要忘记把起点标记为走过！
		dfs(start_x, start_y);     //深搜算法
		if (!flag)    //若没找到，则输出NO
			cout << "NO" << endl;
	}
}
