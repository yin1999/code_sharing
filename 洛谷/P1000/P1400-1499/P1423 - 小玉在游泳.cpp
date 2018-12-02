//等比数列求和，可以选择求对数直接得到答案，
#include<iostream>
#include<cmath>
#define si 0.98
#define v0 2
using namespace std;


int main()
{
	double sum, sum_t = 0;
	int n = 0;
	cin >> sum;
	while (sum_t < sum)
	{
		n++;
		sum_t = v0 * (1 - pow(si, n)) / (1 - si);
	}
	cout << n << endl;
	return 0;
}
