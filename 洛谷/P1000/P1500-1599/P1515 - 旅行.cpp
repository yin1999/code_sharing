//动态规划
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	int a, b, n, i, j;
	cin >> a >> b >> n;
	int dis[34] = { 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000 };
	for (i = 14; i < n + 14; i++)
		cin >> dis[i];
    
	sort(dis, dis + n + 14, cmp);
  
	int plan[34] = { 1 };           //起点算只有一种方案！
	for (i = 1; i < n + 14; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (dis[i] - dis[j] >= a && dis[i] - dis[j] <= b)
				plan[i] += plan[j];
		}
	}
	cout << plan[n + 13] << endl;
	return 0;
}
