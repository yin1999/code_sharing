#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *num = new int[n];
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	long long ans = num[0];
	int temp;
	for (int i = 1; i < n; i++)
	{
		temp = num[i] - i;
		if (temp > 0)          //当可选择的数的个数小于等于0时，说明无法找出满足条件的情况
		{
			ans *= temp;
			ans %= 1000000007;
		}
		else
		{
			ans = 0;
			break;
		} 
	}
	cout << ans << endl;
	return 0;
}
