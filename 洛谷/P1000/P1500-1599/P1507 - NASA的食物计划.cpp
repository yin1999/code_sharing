//动规问题，01背包
//这题与两个量都有关，需要用二维数组来解决
#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int v, m, n, vt, mt, ct;
	int cal[400][400] = { 0 };
	cin >> v >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> vt >> mt >> ct;
		for (int j = v; j >= vt; j--)
		{
			for (int k = m; k >= mt; k--)
				cal[j][k] = max(cal[j][k], cal[j - vt][k - mt] + ct);
		}
	}
	cout << cal[v][m] << endl;
	return 0;
}
