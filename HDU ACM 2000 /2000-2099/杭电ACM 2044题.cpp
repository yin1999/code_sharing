//这题不会的可以参考<https://github.com/yin1999/code_sharing/blob/master/HDU%20ACM%202000%20/2000-2099/%E6%9D%AD%E7%94%B5ACM%202041%E9%A2%98.cpp>
//两题其实是差不多的，都是递归问题，我这题的room也是当作楼梯阶数来处理的，skip变量储存了要走到的那级楼梯，从第一级开始走
#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		long long room[50] = { 0,1 };   //最大会超过32位整数，所以得用long long int型
		int a, b, skip;
		cin >> a >> b;
		skip = b - a + 1;
		for (int i = 2; i <= skip; i++)
			room[i] = room[i - 1] + room[i - 2];
		cout << room[skip] << endl;
	}
	return 0;
}
