//动态规划问题，每次放入一个质量和价值，计算出当前质量下的最优解，一步步向上增加质量
#include<iostream>
#include<algorithm>
using namespace std;

int i, n, m, w, p, j;
int d[13000] = { 0 };

int main()
{
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> w >> p;
		for (j = m; j >= w; j--)
			d[j] = max(d[j], d[j - w] + p);
	}
	cout << d[m] << endl;
	return 0;
}
