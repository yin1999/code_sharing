//思路：因为总共为n个数，所以，总共只有n-1个差。
//当n-1个差里面有重复的，或者其中有差是大于等于n的，那么，它肯定不是"欢乐的跳"

#include <iostream>
#include <cmath>
using namespace std;

bool num[1001] = { false };    //用于记录差值是否出现过

int main()
{
	int n;
	bool flag = true;
	cin >> n;
	int front, behind, d, i;
	cin >> behind;
	for (i = 1; i < n; i++)
	{
		cin >> front;
		d = abs(behind - front);
		if (d < n && num[d] == false)
			num[d] = true;
		else
		{
			flag = false;
			break;
		}
		behind = front;
	}
	for (; i < n; i++)
		cin >> front;
	if (flag && n != 1)
		cout << "Jolly" << endl;
	else
		cout << "Not jolly" << endl;
	return 0;
}
