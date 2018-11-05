#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	int a[3][3];
	cout << "请输入一个3*3的矩阵" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
	}
	cout << a[0][0] + a[1][1] + a[2][2] + a[0][2] + a[2][0] << endl;
	return 0;
}