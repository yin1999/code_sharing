//思想：假设每一个人都是不同桌的，各分配一个桌号，当两个人建立起关系时，将两人的桌号分配成其中较小的那个
#include<iostream>
using namespace std;

int a[1001];   //储存每一个人所在的桌号

void union_f(int c1,int c2,int n)   //给有关系的两个人分配同一桌号（较小的那个）
{
	int max, min;
	if (a[c1] > a[c2])
		max = a[c1], min = a[c2];
	else if (a[c1] < a[c2])
		max = a[c2], min = a[c1];
	else
		return;
	for (int i = max; i <= n; i++)
	{
		if (a[i] == max)
			a[i] = min;
	}
}

int main()
{
	for (int i = 0; i < 1001; i++)
		a[i] = i;     //一开始初始化，假设每一个人的桌号都不一样
	int n, m, c1, c2;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> c1 >> c2;
		union_f(c1, c2, n);
	}
  
	int b[1001] = { 0 };   //用来储存相应桌号有没有人做
	for (int i = 1; i <= n; i++)   //相应桌号有人则赋值为1
		b[a[i]] = 1;
	int count = 0;
	for (int i = 1; i <= n; i++)  //计算有几桌
			count += b[i];
	cout << count << endl;
	return 0;
}
