#include<iostream>
using namespace std;

long long int map[25][25];   //记录到某一点的所有可能性
int g[25][25];  //记录马控制的点

int main() {
	int a, b, n, m;
	cin >> a >> b >> n >> m;

	g[n][m] = 1;
	g[n - 2][m + 1] = 1;
	g[n - 1][m + 2] = 1;
	g[n - 2][m - 1] = 1;
	g[n - 1][m - 2] = 1;
	g[n + 1][m - 2] = 1;
	g[n + 2][m - 1] = 1;
	g[n + 2][m + 1] = 1;
	g[n + 1][m + 2] = 1;

	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			if (g[i][j] == 1) {
				map[i][j] = 0;
			} else {
				if (i == 0 && j == 0) {   //起点
					
					map[i][j] = 1;
					continue;
				}
        
				if (i == 0) {                  //在左侧边界或者顶部边界
					
					map[i][j] = map[i][j - 1];
					continue;
				}
				if (j == 0) {
					
					map[i][j] = map[i - 1][j];
					continue;
				}
        
				map[i][j] = map[i][j - 1] + map[i - 1][j];   //在内部有两种方法可以走到(i,j)向下走一步与向右走一步
			}
		}
	}
	cout << map[a][b];
	return 0;
}
