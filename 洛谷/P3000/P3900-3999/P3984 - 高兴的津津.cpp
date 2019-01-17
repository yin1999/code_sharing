#include <iostream>
using namespace std;

int main()
{
	int n;
	long long t, ans = 0, temp, day = 0;
	cin >> n >> t >> day;
	for (int i = 1; i < n; i++)
	{
		cin >> temp;
		if (day + t > temp)
			ans += temp - day;
		else
			ans += t;
		day = temp;
	}
	cout << ans + t << endl;    //不要忘记最后还有t天
	return 0;
}
