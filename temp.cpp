#include<iostream>
using namespace std;

int main()
{
	int a[41];
	for (int i = 0; i < 41; i++)
		a[i] = 1;
	int count = 41, c = 0, num = 0;
	while (count != 2)
	{
		if (!a[num])
		{
			num++;
			if (num == 41)
				num -= 41;
			continue;
		}
		c++;
		if (c == 3)
			a[num] = 0, c = 0, count--;
		num++;
		if (num == 41)
			num -= 41;
	}
	for (int i = 0; i < 41; i++)
		if (a[i])
			cout << i << " ";
}
