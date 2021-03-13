/*
思路介绍：
递归
要求得有两种情况：
1.n-1个人全部拿错，那就只要那个拿对的和其它n-1个人中任意一个换，有n-1种情况
2.n-1个人中有1个拿对，剩下那一个不管有没有拿对，与那个拿对的换，就是全错，拿对的在n-1个人中有n-1种可能，共n-1种
两者相加为n-1个全拿错*剩下那个人与其中任意一个交换（n-1）加上n-2个全拿错*拿对的那个人在哪里的可能（n-1）
即(n-1)*(n-1个全拿错+n-2个人全拿错）
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int c;
	cin >> c;
	double room[21] = { 0,1 };
	for (int i = 2; i < 21; i++)
		room[i] = i * (room[i - 1] + room[i - 2]);   //注意下标与第几个数的关系，下标比第几个数小1！！！
	while(c--)
	{
		long long n, temp = 1;
		cin >> n;
		for (int i = 2; i <= n; i++)
			temp *= i;
		cout << fixed << setprecision(2) << room[n - 1] / temp * 100 << "%" << endl;
	}
	return 0;
}
