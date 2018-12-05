//字符串处理问题，注意要先读入一行才能知道要输入几个字符串，注意开头为1的情况，要先输出一个0
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[200][201], ch;
	int i = 1, count1 = 1, n = 0;
	cin >> str[0];
	int length = strlen(str[0]);
	for (int j = 0; j < length - 1; j++)
		cin >> str[++n];
	cout << length;
	n = 0;
	ch = str[0][0];
	if (ch == '1')
		cout << " " << 0;
	for (int j = 0; j < length; j++)
	{
		while (str[n][i])
		{
			if (ch != str[n][i])
			{
				ch = str[n][i];
				cout << " " << count1;
				count1 = 0;
			}
			count1++;
			i++;
		}
		i = 0;
		n++;
	}
	cout << " " << count1 << endl;
	return 0;
}
