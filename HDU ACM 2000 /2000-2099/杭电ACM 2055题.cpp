#include<iostream>
using namespace std;

int calc(char str)  //题目里面的f()函数
{
	if (str <= 'Z')
		return (int)str + 1 - 'A';
	else
		return -((int)str + 1 - 'a');
}

int main()
{
	int n;
	cin >> n;
	char str;
	int c;
	for (int i = 0; i < n; i++)
	{
		cin >> str >> c;
		cout << calc(str) + c << endl;
	}
}
