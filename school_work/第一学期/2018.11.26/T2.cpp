#include<iostream>
using namespace std;

void transfer(char *a, char (*m)[12],int ms)
{
	int n = 1;
	char *p = m[ms];
	a[0] = *p;
	while (*p++)
		a[n++] = *p;
}

int main()
{
	char m[][12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	char out[12];
	int n;
	cout << "请输入1-12的整数，输入Ctrl+z" << endl;
	
	while (cin >> n)
	{
		if (n <= 0 || n > 12)
		{
			cout << "输入数据不合法" << endl;
			continue;
		}

		transfer(out, m, n - 1);
		cout << "月份为 " << out << endl;
	}
	return 0;
}
