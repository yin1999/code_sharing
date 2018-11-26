#include<iostream>
using namespace std;

int getint(char *a, int *b)
{
	int count1 = 0;
	int num = 0;
	bool flag = false;
	while (*a)      //判断是否到了字符串结尾
	{
		if (*a >= '0'&&*a <= '9')     //判断是否为数字
		{
			num = num * 10 + *a - '0';     //取出数字，加到num中
			flag = true;    //记录当前数为数字（考虑下一位也是数字或者不是数字的情况
		}
		else if(flag)
		{
			b[count1++] = num;
			num = 0;
			flag = false;
		}
		a++;    //让目前判断的字符后移一位
	}
	if (flag)
		b[count1++] = num;     //不要忘记判断最后一个非空字符是数字的情况
	
	return count1;    //返回整数个数
}

int main()
{
	char a[1000];
	int b[100];
	cout << "请输入任意字符串，输入Ctrl+z终止输入流" << endl;
	while (cin.getline(a,1000))
	{
		int n = getint(a, b);
		if (n == 0)
			cout << "没有整数";
		else
		{
			cout << "有 " << n << " 个整数" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << b[i] << '\t';
			}
		}
		cout << endl;
	}
}
