//动规问题，01背包
#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int m, n, t1, t2, sum_time;    //m记录题目总数，n记录知识点总数，sum_time记录总时间
	cin >> t1 >> t2;
	t1 = t2 / t1;   //t1记录学生用的时间是老师的几倍
	cin >> m >> n;
	int *time = new int[n];     //开辟空间储存每一知识点解题所需时间（学生）
	int *point = new int[m];    //记录每一问题的得分
	int *qtime = new int[m];    //记录每一问题的知识点
	if (time == NULL || point == NULL || qtime == NULL)
		return -1;
	for (int i = 0; i < n; i++)
	{
		cin >> t2;
		time[i] = t2 * t1;
	}
	for (int i = 0; i < m; i++)
		cin >> qtime[i] >> point[i];
	cin >> sum_time;
	long long *sum_point = new long long[sum_time + 1];
	for (int i = 0; i <= sum_time; i++)
		sum_point[i] = 0;
	if (sum_point == NULL)
		return -1;
	for (int q = 0; q < m; q++)
	{
		for (int p = sum_time; p >= time[qtime[q] - 1]; p--)
			sum_point[p] = max(sum_point[p], sum_point[p - time[qtime[q] - 1]] + point[q]);
	}
	cout << sum_point[sum_time] << endl;
	return 0;
}
