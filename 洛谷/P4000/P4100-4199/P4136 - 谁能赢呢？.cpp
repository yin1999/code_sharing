#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		if ((n & 1) == 0)             //判断奇偶性即可
			cout << "Alice" << endl;
		else
			cout << "Bob" << endl;
	}
	return 0;
}
