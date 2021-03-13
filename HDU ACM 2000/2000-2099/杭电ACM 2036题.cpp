#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

struct point
{
	int x, y;
};

float sum(point a, point b)
{
	return a.x*b.y - b.x*a.y;
}


int main()
{
	int n;
	while (cin >> n && n)
	{
		point a[101];
		float sum_all = 0;   //储存总面积
		for (int i = 0; i < n; i++)
			cin >> a[i].x >> a[i].y;
      
		a[n].x = a[0].x;   //别忘记最后一个点和第一个点响铃
		a[n].y = a[0].y;
    
		for (int i = 0; i < n; i++)
			sum_all += sum(a[i], a[i + 1]) / 2;   //多边形面积计算公式，网上有推导方式
		cout << fixed << setprecision(1) << fabs(sum_all) << endl;   //控制格式输出
	}
	return 0;
}
