//此段代码超出内存限制，仅采用它的思想
#include <iostream>  
#include <ctime>
#include <cmath>
#include <algorithm>
#include<iomanip>

using namespace std;

typedef struct Point
{
	float x, y;     //二维点的横纵坐标
}Point;

float Distance(Point a, Point b)      //计算两点之间的距离
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool Cmpx(Point a, Point b)   //自定义排序规则前者x比后者x小
{
	return a.x < b.x;
}

float ClosestPair(Point points[], int length, Point &a, Point &b)
{
	float distance;
	float d1, d2;
	int i = 0, j = 0, k = 0;
	Point a1, b1, a2, b2;   //分别储存左右两个区块的两个点

	if (length < 2)
		return 1000000;    //如果数组小于2，则无最小距离，返回1000000来表示
	else if (length == 2)
	{
		a = points[0];
		b = points[1];
		return Distance(points[0], points[1]);
	}
	else
	{
		Point *pts1 = new Point[length];
		Point *pts2 = new Point[length];

		sort(points, points + length, Cmpx);
		float mid = points[(length - 1) / 2].x;   //记录points中横坐标的中位数到mid中

		for (i = 0; i < length / 2; i++)
			pts1[i] = points[i];
		for (j = 0, i = length / 2; i < length; i++)
			pts2[j++] = points[i];
		d1 = ClosestPair(pts1, length / 2, a1, b1);
		d2 = ClosestPair(pts2, length - length / 2, a2, b2);
		if (d1 < d2)
		{
			distance = d1;
			a = a1;
			b = b1;
		}
		else
		{
			distance = d2;
			a = a2;
			b = b2;
		}

		Point *pts3 = new Point[length];
		for (i = 0, k = 0; i < length; i++)
		{
			if (abs(points[i].x - mid) <= distance)
				pts3[k++] = points[i];
		}
		for (i = 0; i <= i + 7 && j < k; j++)
		{
			if (Distance(pts3[i], pts3[j]) < distance)
			{
			distance = Distance(pts3[i], pts3[j]);
			a = pts3[i];
			b = pts3[j];
			}
		}
	}
	return distance;
}


int main()
{
	int N;
	Point a, b;    //用于存储两个point型的变量
	float distance;    //存储距离
	while (cin >> N)
	{
		if (N == 0)   //若输入数组个数限制为0则退出，1则重新输入
			break;
		else if (N == 1)
			continue;
		Point *points = new Point[N];
		for (int i = 0; i <= N-1; i++)
			cin >> points[i].x >> points[i].y;
		distance = ClosestPair(points, N, a, b);
		cout << fixed << setprecision(2) << distance / 2 << endl;
	}
}
