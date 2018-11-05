#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	int a[1000];
	int i = 0;
	cout << "输入\'Ctrl+z\'结束输入，最多输入1000个数" << endl;
	while (cin >> a[i])
	{
		i++;
	}
	cout << "其逆序数为" << endl;
	while (i--)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}