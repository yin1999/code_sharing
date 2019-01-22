//输入、排序、计算
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	int* M_i = new int[n];
	int* B_i = new int[n];
	for (int i = 0; i < n; i++)
		cin >> M_i[i] >> B_i[i];
	sort(M_i, M_i + n);
	sort(B_i, B_i + n);
	int sum = 0, temp;
	for (int i = 0; i < n; i++)
	{
		temp = B_i[i] - M_i[i];
		if (temp > 0)
			sum += temp * x;
		else
			sum -= temp * y;
	}
	cout << sum << endl;
	delete[] M_i;
	delete[] B_i;
	return 0;
}
