#include<iostream>
using namespace std;


int main()
{
	int a[8] = { 3,1,4,3,7,8,5,6 };
	for (int i = 0; i < 8; i++)
	{
		int temp = i;
		for (int j = i + 1; j < 8; j++)
		{
			if (a[temp] > a[j])
				temp = j;
		}
		int coach = a[i];
		a[i] = a[temp];
		a[temp] = coach;
	}
	for (int c = 0; c < 8; c++)
		cout << a[c] << " ";
	return 0;
}
