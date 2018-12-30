//这题需要标记前面的状态是否为减小，当前的状态是否为上升，如果满足着两点，则有一个水洼（注意两点相等的情况）
#include <iostream>
using namespace std;

int main()
{
	int n, front, behind, count1 = 0;
	bool flag_down = false;
	cin >> n;
	cin >> front;
	for (int i = 1; i < n; i++)
	{
		cin >> behind;
		if (behind < front)
		{
			flag_down = true;
		}
		else if (behind > front && flag_down)
		{
			count1++;
			flag_down = false;
		}
		front = behind;
	}
	cout << count1 << endl;
	return 0;
}
