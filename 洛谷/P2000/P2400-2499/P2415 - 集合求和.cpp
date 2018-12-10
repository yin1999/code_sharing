//每一个数出现的次数都为2的n- 1次（n为集合内元素个数）
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int temp, count1 = 0;
	long long sum = 0;
	while (cin >> temp)
	{
		sum += temp;
		count1++;
	}
	cout << sum * (long long)pow(2, count1 - 1) << endl;
	return 0;
}
