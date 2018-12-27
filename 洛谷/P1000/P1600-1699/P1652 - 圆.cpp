//只有起点和终点一个在圆外一个在圆内时，会穿过一次边界，其它情况一律不穿过边界
#include <iostream>
#include <cmath>
using namespace std;

struct point    //记录点的x, y, 半径
{
	int x;
	int y;
	int r;
};

int main()
{
	point p[50];
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> p[i].x;
	for (i = 0; i < n; i++)
		cin >> p[i].y;
	for (i = 0; i < n; i++)
		cin >> p[i].r;
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int count1 = 0;               //计数
	double d1, d2;
	for (i = 0; i < n; i++)
	{
		d1 = sqrt(pow(p[i].x - x1, 2) + pow(p[i].y - y1, 2));   //记录起点与圆心的距离
		d2 = sqrt(pow(p[i].x - x2, 2) + pow(p[i].y - y2, 2));   //记录终点与圆心的距离
    
		if (d1 > p[i].r && d2 < p[i].r)       //两种情况，1.起点在内终点在外，2.起点在外终点在内
			count1++;
		else if (d1 < p[i].r && d2 > p[i].r)
			count1++;
      
	}
	cout << count1 << endl;
	return 0;
}
