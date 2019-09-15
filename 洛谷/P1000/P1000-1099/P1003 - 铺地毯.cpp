#include<iostream>
using namespace std;

int a[10000][4];
int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a[i][j];
		}
	}
	int x, y, count1 = -2;
	cin >> x >> y;
	for (int i = 0; i < n; i++) {
		if (a[i][0]<=x&&a[i][1]<=y&&a[i][0] + a[i][2]>=x&&a[i][1] + a[i][3]>=y)
			count1 = i;
	}
	cout << count1 + 1;
	return 0;
}
