//每两人之间比赛要使等级差最小，则他们两人的等级要是相邻的，中间没有第三个人，那么，可以在输入数据后对数据进行排序
//然后计算出所有的等级差，这样保证了每个人最多和一个等级比他低，一个比他高的人比赛
//然后，将等级差排序，选出最小的k个数据求和，就是答案
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int * num = new int[n];
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	for (int i = 0; i < n - 1; i++)
		num[i] = num[i + 1] - num[i];
	sort(num, num + n - 1);
	int sum = 0;
	for (int i = 0; i < k; i++)
		sum += num[i];
	cout << sum << endl;
	delete[] num;
	return 0;
}
