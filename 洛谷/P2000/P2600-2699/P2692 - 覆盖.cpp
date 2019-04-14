/*
首先，统计男孩和女孩打扫过的行和列的总数，然后，总面积 减去 未打扫过的行数和未打扫过的列数之积 就是答案
*/
#include <iostream>
using namespace std;

int main()
{
	int B, G, N, M, i, j;
	cin >> N >> M >> B >> G;
	int* R = new int[N];
	int* C = new int[M];
	for (i = 0; i < N; i++)
		R[i] = 0;
	for (i = 0; i < M; i++)
		C[i] = 0;
	int a, b;
	for (i = 0; i < B; i++)
	{
		cin >> a >> b;
		for (j = a - 1; j < b; j++)
			R[j] = 1;
	}
	for (i = 0; i < G; i++)
	{
		cin >> a >> b;
		for (j = a - 1; j < b; j++)
			C[j] = 1;
	}
	int rows = 0, cols = 0;
	for (i = 0; i < N; i++)
		rows += R[i];
	for (i = 0; i < M; i++)
		cols += C[i];
	cout << N * M - (N - rows) * (M - cols) << endl;
 	return 0;
}
