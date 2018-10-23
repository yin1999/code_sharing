#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

typedef struct point  //定义point类型，储存x，y坐标
{
	float x, y;
}point;

int main()
{
	point *points = new point[2];
	while (cin >> points[0].x >> points[0].y >> points[1].x >> points[1].y)
	{
		cout << fixed << setprecision(2) << sqrt((points[0].x - points[1].x)*(points[0].x - points[1].x) + (points[0].y - points[1].y)*(points[0].y - points[1].y)) << endl;
	}
}
