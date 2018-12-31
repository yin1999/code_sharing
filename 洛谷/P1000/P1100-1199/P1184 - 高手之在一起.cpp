//此题坑人点：输入的字符串后面自带一个ASCII码为13的字符，但最后一个没有！！！！
//于是乎，我们需要给最后一个字符串末尾加上一个ASCII码为13的字符
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n, m, count1 = 0;
	cin >> n >> m;
	char (*str1)[50] = new char[n][50];
	char str2[50];
	while (getchar() != '\n');
	for (int i = 0; i < n; i++)
		cin.getline(str1[i], 50);
	for (int i = 0; i < m; i++)
	{
		cin.getline(str2, 50);
		if (str2[strlen(str2) - 1] != 13)
		{
			str2[strlen(str2)] = 13;
			str2[strlen(str2) + 1] = 0;
		}
		for (int j = 0; j < n; j++)
		{
			if (strcmp(str1[j], str2) == 0)
			{
				count1++;
				break;
			}
		}
	}
	cout << count1 << endl;
	delete[] str1;
	return 0;
}
