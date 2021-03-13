/*
思路详解：
需要知道涂到第i个各自有几种方法时，需要分类讨论
1. 第i-1个格子和第1个格子颜色不同，则第i个格子只能涂一种颜色，有涂到i-1格应有的涂法
2.第i-1格与第一个格子颜色相同，则涂到第i-1格的涂法和到第i-2格的涂法次数一样，到第i格则有到第i-2格2倍的涂法
两者相加便是总次数
*/
#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		long long room[50] = { 3,6,6 };
		for (int i = 3; i < n; i++)
			room[i] = room[i - 1] + 2 * room[i - 2];
		cout << room[n - 1] << endl;
	}
	return 0;
}
