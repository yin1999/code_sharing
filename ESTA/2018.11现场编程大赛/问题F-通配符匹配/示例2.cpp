//思想：从后向前比较，字符相同赋空值，直到找到不同字符，再进行判断，不同字符中字符串s是否有*，
//若有，则将其赋空值，并判断字符串t后面的字符是否合法，若不合法则不变动，合法则全部赋空值
#include<iostream>
#include<string.h>
using namespace std;

char s[10000], t[10000];

int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

void zeroer(char temp1[], char temp2[], int i)   //字符串赋空值（*号判断及字符串合法判断）
{
	if (temp1[i] == '*')
	{
		temp1[i] = '\0';
		int j;
		for (j = i; temp2[j] != '\0'; j++)
		{
			if (temp2[j]<'a' || temp2[j]>'z')
				return;
		}
		for (; i < j; i++)
		{
			temp2[i] = '\0';
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	cin >> s >> t;
	int i = 1;
	for (; i <= min(n, m); i++)   //从后向前赋空值
	{
		if (s[n - i] == t[m - i])
		{
			s[n - i] = '\0';
			t[m - i] = '\0';
		}
		else
			break;
	}
	if (i <= n)
		zeroer(s, t, n - i);
	else if (i == n + 1 && i == m + 1)
	{
		cout << "YES" << endl;
		return 0;
	}
	else
	{
		cout << "NO" << endl;
		return 0;
	}
	if (strcmp(s, t) == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
