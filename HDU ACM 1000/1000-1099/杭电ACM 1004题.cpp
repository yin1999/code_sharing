#include<iostream>
#include<string>
using namespace std;
int main()
{
	while (1)     //循环用于实现多次输入
	{
		string str[1001];
		bool flag[1001] = { 1 };   //用于记录该字符串是否被计数，若计数，则赋值0，同时减少运算量
		int a, strc[1001] = { 0 },temp=1,i;     //temp记录最大计数书，strc数组用于记录同类型计数
		cin >> a;      //输入a，用来记录接下来将输入几个字符串组
		if (a == 0) break;     //若输入0则退出，停止输入
		for (i = 1; i <= a; i++)
			cin >> str[i];
		for (i = 1; i <= a; i++)
		{
			if (flag[i]) continue;       //若该组被计数（标记flag为false(0)）则跳过此次循环
			for (int j = i + 1; j <= a; j++)
				if (str[i] == str[j])
				{
					strc[i]++;
					flag[i] = 0;
				}
			if (strc[temp] < strc[i]) temp = i;
		}
		cout << str[temp]<<endl;   //输出最大计数类型
	}
	return 0;
}
