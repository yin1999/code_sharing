#include<iostream>
#include<cmath>
using namespace std;

bool prime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int a[99], isprime[50], c = 0;
	for (int i = 0; i < 99; i++)
		a[i] = i + 2;
	for (int j = 0; j < 99; j++)
	{
		if (a[j] && prime(a[j]))
		{
			isprime[c] = a[j];
			c++;

			for (int k = 2; k*a[j] <= 100; k++)
				a[k*a[j] - 2] = 0;
		}
	}
	for (int i = 0; i < c; i++)
		cout << isprime[i] << " ";
	cout << endl;
	return 0;
}
