//本题使用了两个比较重要的东西：1.曼哈顿距离（不懂去search） 2.地图访问标记
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int maze[1000][1000] = { 0 };   //创建一个1000*1000的空地图，全部标记为0（未被访问过）

int  main()
{
	int n, m, k, x, y;
	cin >> n >> m >> k;   //输入地图大小，火把个数，萤石个数
	long long int sum = n * n;    //定义sum（储存怪物出现的点个数）初始化为n * n
	for (int i = 0; i < m; i++)    //处理火把
	{
		cin >> x >> y;   //输入火把坐标（实际坐标）
		x--;     //在C/C++里面，数组从0开始，一定要减一计算啊
		y--;     //同上
		for (int y0 = max(y - 2, 0); y0 <= min(y + 2, n - 1); y0++)   //想一下火把覆盖的地面，如果在边缘，需要考虑火把可能没有被完全利用（从下向上分别考虑下边界和上边界）
		{
			for (int x0 = max(x - (2 - abs(y0 - y)), 0); x0 <= min(x + (2 - abs(y0 - y)), n - 1); x0++)    //火把能照亮的点到火把的曼哈顿距离最大值为2
				if (maze[y0][x0] == 0)   //判断该点是否被标记为1
				{
					sum--;               //若标记为0，则表示它原来还是暗的，得让怪兽出现点的个数自减
					maze[y0][x0] = 1;    //把该点标记为1，已经被照亮
				}
		}
	}
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;   //同火把
		x--;
		y--;
		for (int y0 = max(y - 2, 0); y0 <= min(y + 2, n - 1); y0++)    //同火把，而且好处理多了，不需要考虑曼哈顿距离
		{
			for (int x0 = max(x - 2, 0); x0 <= min(x + 2, n - 1); x0++)
				if (maze[y0][x0] == 0)
				{
					sum--;
					maze[y0][x0] = 1;
				}
		}
	}
	cout << sum << endl;   //输出结果
	return 0;
}
