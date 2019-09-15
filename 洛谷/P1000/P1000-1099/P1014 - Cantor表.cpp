//规律，先按第10行到第13行的循环算出对应的行数与对应第几个数(每行数对应增加1)，每行的分子分母之和为(行数加一)
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int i = 1;
	while (i < n) {
		n -= i++;
	}
	if ((i & 1) == 0) {
		cout << n << '/' << i + 1 - n << endl;
	} else {
		cout << i + 1 - n << '/' << n << endl;
	}
	return 0;
}
