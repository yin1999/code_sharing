#include<iostream>
using namespace std;

bool judge(int a)
{
	if (a % 7 == 0)
		return true;
	else
	{
		while (a)
		{
			if (a % 10 == 7)
				return true;
			a /= 10;
		}
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int p, temp;
		cin >> p;
		temp = p;
		int num = 1;
		while (temp)
		{
			if (judge(num))
				temp--;
			else
				temp = p;
			num++;
		}
		cout << num - p << endl;
	}
}
