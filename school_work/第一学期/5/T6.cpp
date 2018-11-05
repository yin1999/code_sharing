[不会的话看这个](https://github.com/yin1999/code_sharing/blob/master/HDU%20ACM%202000%20/2000-2099/%E6%9D%AD%E7%94%B5ACM%202032%E9%A2%98.cpp)
#include<iostream>
using namespace std;

int main()
{
	int a[10], b[10];
	a[0] = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				b[j] = 1;
			else
				b[j] = a[j] + a[j - 1];
			cout << b[j] << " ";
		}
		cout << endl;
		for (int k = 0; k <= i; k++)
			a[k] = b[k];
	}
	return 0;
}
