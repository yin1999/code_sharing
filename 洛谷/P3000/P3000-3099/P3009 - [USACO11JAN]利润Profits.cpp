//贪心算法，每输入一个数后进行求和，若求和结果大于之前得到的最大数列和(一开始最大数列和初始化为-MAX_INTEGER)，若求和结果小于0， 初始化求和结果为0
//即舍弃前面的数列，继续对后面的数列进行相同的操作
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int temp, sum = 0, ans = -0x7fffffff;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		sum += temp;
		ans = max(ans, sum);
		sum = max(sum, 0);
	}
	cout << ans << endl;
	return 0;
}
