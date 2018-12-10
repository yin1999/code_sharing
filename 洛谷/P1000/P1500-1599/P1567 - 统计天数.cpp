#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int temp1, temp2, temp_max = 1, max = 1;  //temp_max储存当前连续升温天数，注意，赋初值为1，不能为0
	cin >> temp1;
	for (int i = 1; i < n; i++)
	{
		cin >> temp2;
		if (temp2 > temp1)
		{
			temp_max++;
		}
		else
		{
			if (temp_max > max)   //当当前连续升温天数大于最大连续天数时，最大连续天数赋新值
				max = temp_max;
			temp_max = 1;   //注意是1
		}
		temp1 = temp2;
	}
	cout << max << endl;
	return 0;
}
