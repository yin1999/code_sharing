#include <iostream>
using namespace std;

struct CrossRoad
{
	int Di;    //距当前一个十字路口的路程
	int Ri;    //当前十字路口的红灯时间
	int Gi;    //当前十字路口的绿灯时间
};

int main()
{
	int n, sum_time = 0, i, remain;
	cin >> n;
	CrossRoad *point = new CrossRoad[n];
  
	for (i = 0; i < n; i++)    //接收距离、时间
		cin >> point[i].Di;
	for (i = 0; i < n; i++)
		cin >> point[i].Ri;
	for (i = 0; i < n; i++)
		cin >> point[i].Gi;
    
	for (i = 0; i < n; i++)
	{
		sum_time += point[i].Di;
		remain = sum_time % (point[i].Gi + point[i].Ri);
		if (remain > point[i].Gi)
			sum_time += point[i].Gi + point[i].Ri - remain;
		cout << sum_time << endl;
	}
  
	delete[] point;
  
	return 0;
}
