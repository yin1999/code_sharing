#include <iostream>
using namespace std;

int main()
{
	long long a, c, p, q, r, x, ans;
	cin >> a >> c >> p >> q >> r >> x;
	long long dt = c - a;
	if (dt > 0)
	{
		if (dt * p > x)
		{
			ans = a + x / p;
		}
		else
		{
			x -= dt * p;
			dt = 0;
		}
	}
	if (dt == 0)
	{
		if (q > x)
			ans = c;
		else
		{
			x -= q;
			dt = -1;
		}
	}
	if (dt < 0)
	{
		if (c - a >= 0)      //用来排除实际温度小于等于融点的情况
			dt = 0;
		ans = c - dt + x / r;
	}
	cout << ans << endl;
	return 0;
}
