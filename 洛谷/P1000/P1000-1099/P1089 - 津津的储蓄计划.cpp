#include <iostream>
using namespace std;

int main()
{
	int sum = 0, i, pre_pay, changes = 0;
	for (i = 1; i <= 12; i++)
	{
		cin >> pre_pay;
		changes += 300 - pre_pay;
		if (changes < 0)
			break;
		sum += changes - changes % 100;
		changes = changes % 100;
	}
	if (i != 13)
	{
		for (int j = i; j <= 12; j++)
			cin >> pre_pay;
		cout << '-' << i << endl;
	}
	else
		cout << sum * 1.2 + changes << endl;
	return 0;
}
