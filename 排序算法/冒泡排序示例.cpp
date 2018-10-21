#include<iostream>
using namespace std;


int main()
{
	int a[8] = { 3,1,4,3,7,8,5,6 };
	for (int i = 0; i < 7; i++)
	{
		for (int j = 7; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				a[j] += a[j - 1];
				a[j - 1] = a[j] - a[j - 1];
				a[j] = a[j] - a[j - 1];
			}
		}
	}
	for (int c = 0; c < 8; c++)
		cout << a[c] << " ";
	return 0;
}
