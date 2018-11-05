#include<iostream>
using namespace std;

int main()
{
	int a[1000];
	int i = 0;  //储存输入了几个数
	cout << "输入\'Ctrl+z\'结束输入，最多输入1000个数" << endl;
	while (cin >> a[i])   //Ctrl+z是结束输入流
	{
		i++;   //计数器自增
	}
	cout << "其逆序数为" << endl;
	while (i--)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
