#include <iostream>
using namespace std;

int main()
{
	double v = 7, s, x;
	cin >> s >> x;
	while (s > x)   //循环至小鱼进入探测器范围
	{
		s -= v;
		v *= 0.98;
	}
	if(s + x >= v)   //若再游1秒不能出去，则输出y
		cout << 'y';
	else
		cout << 'n';    //否则输出n
	cout << endl;
	return 0;
}
