#include<iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		getchar();     //这行不要忘，写在循环外面也不行，cin.get()和getchar一样，对回车键敏感，它遇到回车键就停止输入并自动在字符串后加'\0'
		char str[100000];
		int num = 0;
		cin.get(str,1024);
		int length = strlen(str);
		for (int i = 0; i < length; i++)
		{
			if (str[i] < ' ')     //按中文的编码规则，每一个字节的值会小于0，则判断如果小于0，就是汉字，同时i step 2，一个汉字占两个字节
			{
				num++;
				i++;   //step 2
			}
		}
		cout << num << endl;
	}
	return 0;
}
