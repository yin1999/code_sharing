#include<iostream>
#include<string>
using namespace std;

string addup(string num1, string num2)    //定义大数相加函数
{
	if (num1.size() < num2.size())    //判断两数长度，更长的放在num1，方便计算
	{
		string temp = num1;
		num1 = num2;
		num2 = temp;
	}
	int length1 = num1.size(), length2 = num2.size(), flag = 0, sum, a, b;
	while (length1 > 0)
	{
		a = num1[length1 - 1] - '0';        //ASCII码运算处理，从字符中提取数字
		if (length2 > 0)
			b = num2[length2 - 1] - '0';
		else b = 0;
		sum = a + b + flag;
		if (sum >= 10)
		{
			num1[length1 - 1] = '0' + sum % 10;
			flag = 1;
		}
		else 
		{
			num1[length1 - 1] = '0' + sum;
			flag = 0;
		}
		length1--;
		length2--;
	}
	if (flag == 1)
		num1 = "1" + num1;     //若最高位要进一，则通过这一步实现
	return num1;
}
int main()      //main函数为杭电acm的问题1002
{
	int t, k;
	string num1, num2;
	cin >> t;
	for (k = 1; k < t; k++)
	{
		cin >> num1 >> num2;
		cout << "Case " << k << ":" << endl << num1 << " + " << num2 << " = " << addup(num1, num2) << endl << endl;
	}
	cin >> num1 >> num2;
	cout << "Case " << k << ":" << endl << num1 << " + " << num2 << " = " << addup(num1, num2) << endl;
	return 0;
}
