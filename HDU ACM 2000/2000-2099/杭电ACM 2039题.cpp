#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		float a, b, c;   //正数可能是小数!
		cin >> a >> b >> c;
		if (a < b + c && a > fabs(b - c))   //三角形判别式，只要其中一边小于其它两边之和并大于其它两边之差及三角形成立，写三个小于其它两边之和也可
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
