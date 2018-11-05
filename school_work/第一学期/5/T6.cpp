#include<iostream>
#include<cstdlib>
#include<ctime>
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