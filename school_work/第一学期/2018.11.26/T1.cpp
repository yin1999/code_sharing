#include<iostream>
using namespace std;

int getint(char *a, int *b)
{
	int count1 = 0;
	int num = 0;
	bool flag = false;
	while (*a)
	{
		if (*a >= '0'&&*a <= '9')
		{
			num = num * 10 + *a - '0';
			flag = true;
		}
		else if(flag)
		{
			b[count1++] = num;
			num = 0;
			flag = false;
		}
		a++;
	}
	if (flag)
		b[count1++] = num;

	return count1;
}

int main()
{
	char a[1000];
	int b[100];
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
