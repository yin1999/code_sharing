/*
此题一共有三种情况：
1.黑三角只有一条边与其它三角形相接，那么，野猫必胜
2.黑三角有两条边与其它三角形相接，那么，当其它三角形的总个数减2是偶数时，最后剩下两个三角形与黑三角相接，此时，野猫先手，胖子必赢
为奇数时，最后剩下两个三角形与黑三角相接，此时，胖子先手，野猫必赢
3.黑三角有三条边与其它三角形相接，与2一样，切去一个变成情况2，所以，可以与2合并考虑
*/
#include <iostream>
using namespace std;

int main()
{
	int n, count1 = 0, num;
	cin >> n;
	int black_a, black_b, black_c;
	int current_a, current_b, current_c;
	cin >> black_a >> black_b >> black_c;     //记录黑三角的位置
	for (int i = 3; i < n; i++)
	{
  
		cin >> current_a >> current_b >> current_c;    //判断接收的三角形是否与黑三角有一条边共线
		if (count1 < 3)
		{
			num = 0;
			if (current_a == black_a || current_a == black_b || current_a == black_c)
				num++;
			if (current_b == black_a || current_b == black_b || current_b == black_c)
				num++;
			if (current_c == black_a || current_c == black_b || current_c == black_c)
				num++;
			if (num == 2)
				count1++;
		}
    
	}
	if (count1 == 1)
		cout << "JMcat Win" << endl;
	else
	{
		if (((n - 3 - 2) & 1) == 0)
			cout << "PZ Win" << endl;
		else
			cout << "JMcat Win" << endl;
	}
	return 0;
}
