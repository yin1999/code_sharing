#include <iostream>
using namespace std;

bool prime(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0)
			return true;
		else if (year % 400 == 0)
			return true;
	}
	return false;
}

int main()
{
	int n;
	int week[7] = { 0 }, weekday = 0, i, j;
	cin >> n;
	n += 1900;
	int d_week[2][11] = { {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2}, {3, 1, 3, 2, 3, 2, 3, 3, 2, 3, 2} };  //分别为平年和闰年每个月对13号的星期造成的影响天数，如一月到二月，13号向后推3个日期，由周六变为周二
	for (i = 1900; i < n; i++)
	{
		if (prime(i))
		{
			week[weekday]++;
			for (j = 0; j < 11; j++)
			{
				weekday += d_week[1][j];
				if (weekday >= 7)
					weekday -= 7;
				week[weekday]++;
			}
			weekday += 3;
			if (weekday >= 7)
				weekday -= 7;
		}
		else
		{
			week[weekday]++;
			for (j = 0; j < 11; j++)
			{
				weekday += d_week[0][j];
				if (weekday >= 7)
					weekday -= 7;
				week[weekday]++;
			}
			weekday += 3;
			if (weekday >= 7)
				weekday -= 7;
		}
	}
	cout << week[0];
	for (i = 1; i < 7; i++)
		cout << ' ' << week[i];
	cout << endl;
	return 0;
}
