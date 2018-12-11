//题目要求把输入的数列切段求和，和不超过给的上限，所以，不需要排序处理，直接求和判断
#include <iostream>
using namespace std;

int main()
{
	int n, m, ans = 1, sum = 0, temp;  //ans先赋1，也可以赋0后面再自增
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		sum += temp;
		if (sum > m)
		{
			ans++;
			sum = temp;
		}
	}
	cout << ans << endl;
	return 0;
}
