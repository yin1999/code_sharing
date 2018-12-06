//此题说明可以使用模拟，所以使用地图直接记录每一个点的情况
#include <iostream>
using namespace std;

int maze[101][101] = { 0 };   //记录每一个点被轰炸的次数
int times[101][101] = { 0 };  //记录每一个点最后一次被轰炸是第几轮

struct point
{
	int x;
	int y;
};

int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	point *p = new point[y];
	for (int i = 1; i <= x; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j <= y2; j++)
		{
			for (int k = x1; k <= x2; k++)
			{
				maze[k][j]++;
				times[k][j] = i;
			}
		}
	}
	for (int i = 0; i < y; i++)
		cin >> p[i].x >> p[i].y;
	for (int i = 0; i < y; i++)
	{
		if (maze[p[i].x][p[i].y])
			cout << 'Y' << ' ' << maze[p[i].x][p[i].y] << ' ' << times[p[i].x][p[i].y] << endl;
		else
			cout << 'N' << endl;
	}
	delete[] p;
	return 0;
}
