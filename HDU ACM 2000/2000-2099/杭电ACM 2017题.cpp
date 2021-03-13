#include<iostream>
using namespace std;

int main()
{
	int n;
	char str[1000];
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> str;
			int count = 0;   //数字计数器，初始化为0
			for (int j = 0;str[j]!='\0';j++)
			{
				if (str[j] >= '0'&&str[j] <= '9')
					count++;
			}
			cout << count << endl;
		}
	}
	return 0;
}
