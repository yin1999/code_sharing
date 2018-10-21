#include<iostream>
using namespace std;

int main()
{
	int a[8] = { 3,1,4,3,7,8,5,6 };
	for (int i = 1; i < 8; i++)
	{
		int temp = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j] > temp; j--)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}
	for (int c = 0; c < 8; c++)
		cout << a[c] << " ";
	return 0;
}
