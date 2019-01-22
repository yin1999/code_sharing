#include <iostream>
using namespace std;

int main()
{
	unsigned n, Front, Behind;
	cin >> n;
	Front = n >> 16;
	Behind = n << 16;
	n = Front + Behind;
	cout << n << endl;
	return 0;
}
