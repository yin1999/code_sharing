#include <iostream>
using namespace std;

int main() {
	int n = 0, k;
	double sum = 0;
	cin >> k;
	while (k >= sum) {
		n++;
		sum += 1. / n;
	}
	cout << n << endl;
	return 0;
}
