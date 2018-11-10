#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		float a, b, c;   //题目里面是小于1000的正整数，但定义int就给错，不看别人的代码根本找不出错！
		cin >> a >> b >> c;
		if (a < b + c && a > fabs(b - c))   //三角形判别式，只要其中一边小于其它两边之和并大于其它两边之差及三角形成立，写三个小于其它两边之和也可
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
