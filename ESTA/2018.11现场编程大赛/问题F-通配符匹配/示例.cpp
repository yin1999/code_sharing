#include<iostream>
using namespace std;

int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

int main()
{
	int n, m;
	cin >> n >> m;
	char a[200000], b[200000];
	cin >> a >> b;
	if (n > m + 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	int start = 0, end = 0;
	for (; start < min(n, m); start++)   //从前向后比较，直到比较到最后或者找出第一个不同字符
		if (a[start] != b[start])
			break;
	if (start == n && start == m)   //当上面的循环比较到最后一位仍相等时，只要两个字符串长度相同，则输出YES（此时的start因为最后一次自增而等于字符串长度）
	{
		cout << "YES" << endl;
			return 0;
	}
	for (; end < min(n, m) - start; end++)   //从后向前比较，找出第一个不同字符或与前面的start相遇
		if (a[n - end - 1] != b[m - end - 1])
			break;
	for (int i = start - 1; i < m - end; i++)   //比较b中间的不同字符，若有在小写字符范围外的，直接输出NO
		if (b[i]<'a' || b[i]>'z')
		{
			cout << "NO" << endl;
			return 0;
		}
	if (start + end + 1 != n)   //若a数组中有两个及以上字符与b不同（start位与end位各一个），则输出NO
	{
		cout << "NO" << endl;
		return 0;
	}
	else if (a[start] == '*')  //若只有一个不同，且a的那一位恰好是*号，则输出YES
		cout << "YES" << endl;
	else
		cout << "NO" << endl;   //若不是*号，则输出NO
	return 0;
}
