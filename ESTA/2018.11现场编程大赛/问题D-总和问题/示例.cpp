#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	int a;
	for (int i = (int)sqrt(2*m); i >= 1; i--)
	{
		a = a = (m - ((i - 1)*i) / 2) / i;
		if (m == a * i + (i*(i - 1)) / 2 && a > 0)
			if (a + i - 1 <= n)
				cout << "[" << a << " , " << a + i - 1 << "]" << endl;
	}
	return 0;
}
