//不考虑函数库中的函数名，字符串长度不超过50
#include<iostream>
using namespace std;

bool judge(char a)    //判断是否为合法字符，合法则return  true
{
	if (a >= 48 && a <= 57)   //-->"0-9"
		return true;
	else if (a >= 65 && a <= 90)  //-->"A-Z"
		return true;
	else if (a == 95)   //-->"_"
		return true;
	else if (a >= 97 && a <= 122)   //-->"a-z"
		return true;
	else
		return false;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		bool flag = true;
		char str[51];   //储存字符串
		int count = 0;   //记录字符串长度
		getchar();     //回车终结者
		
		for (int i = 0; i < 51; i++)
		{
			str[i] = getchar();
			if (str[i] == '\n')
				break;
			count++;
		}
		if (!(str[0] >= 'a' &&str[0] <= 'z') && !(str[0] >= 'A'&&str[0] <= 'Z'))
		{
			flag = false;
		}
		for (int j = 1; j < count; j++)
		{
			if (!judge(str[j]))
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
