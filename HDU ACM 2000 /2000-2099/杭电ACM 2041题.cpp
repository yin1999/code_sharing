#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int m[41] = { 0,1 }, level;   m储存到相应楼层有的路径方法
		cin >> level;
		for (int i = 2; i <= level; i++)
		{
			m[i] = m[i - 1] + m[i - 2];   //到相应层数的路径数量等于上一级的路径数量加上上级的路径数量(step为1或者2)
		}
		cout << m[level] << endl;
	}
  return 0;
}
