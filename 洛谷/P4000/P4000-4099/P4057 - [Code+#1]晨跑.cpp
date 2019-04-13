#include <iostream>
using namespace std;

unsigned long long FindMaxFac(unsigned long long a, unsigned long long b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

int main()
{
	unsigned long long a, b, c;
	cin >> a >> b >> c;
	if (a > b)
		swap(a, b);
	if (a > c)
		swap(a, c);
	if (b > c)
		swap(b, c);
	unsigned long long mid_num = a / FindMaxFac(a, b) * b;
	cout << c / FindMaxFac(c, mid_num) * mid_num << endl;
	return 0;
}
