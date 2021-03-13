#include<iostream>
#include<algorithm>
#define MAX 0x7fffffff   //int型最大数
using namespace std;

void init(double *time, int x)   //用于初始化dp数组
{
	for (int i = 0; i < x; i++)
		time[i] = MAX;
}

int main()
{
	double dp[111];    //记录到某一充电桩的最短时间（包括起点和终点）
	int dis[111];     //充电桩到起点距离
	double l, c, t;    //分别记录轨道长度，电动车充满电后行驶距离，充电所需时间
	int n;    //充电站个数
	double vr, v1, v2;    //兔子速度，乌龟开车的速度和蹬车的速度
	while (cin >> l)
	{
		cin >> n >> c >> t;
		cin >> vr >> v1 >> v2;
		for (int i = 1; i <= n; i++)
			cin >> dis[i];
		init(dp, n + 2);   //初始化到每一个充电桩的时间，到终点的时间
		dp[0] = -t;     //用于忽略第一次充电时间
		dis[0] = 0;   //dis[0]为起点
		dis[n + 1] = (int)l;     //dis[n+1]为终点
		for (int i = 1; i <= n + 1; i++)   //动态规划计算到某一充电桩的最短时间
		{
			for (int j = 0; j < i; j++)
			{
				if (c >= dis[i] - dis[j])
					dp[i] = min(dp[i], t + dp[j] + (dis[i] - dis[j]) / v1);
				else
					dp[i] = min(dp[i], t + dp[j] + c / v1 + (dis[i] - dis[j] - c) / v2);
			}
		}
    
		if (dp[n + 1] > l / vr)
			cout << "Good job,rabbit!" << endl;
		else
			cout << "What a pity rabbit!" << endl;
	}
	return 0;
}
