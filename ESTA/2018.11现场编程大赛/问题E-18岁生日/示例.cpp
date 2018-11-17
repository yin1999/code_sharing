#include<iostream>
#include<cmath>
using namespace std;

bool judge_leapyear(int year)   //闰年判断
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}

int main()
{
	int y, m, d, T;
	cin >> T;   //输入样例个数
	while (T--)
	{
		int day = 0;
		cin >> y >> m >> d;
		m = abs(m);
		d = abs(d);
		if (m == 2 && m == 29&& !judge_leapyear(y+18))   //若在闰年的2月29日出生，则判断18年后的那一天是否存在，不存在输出-1
		{
			cout << "-1" << endl;
			continue;
		}
		if (m > 2)    //判断2月后出生还是2月及以前出生
			for (int n = 1; n <= 18; n++)   //二月后出生需要判断下一年是否为闰年来计算经历时间
			{
				if (judge_leapyear(y + n))
					day += 366;
				else
					day += 365;
			}
		else
			for (int n = 0; n < 18; n++)   //二月及以前出生需要判断当年是否为闰年来计算经历时间
			{
				if (judge_leapyear(y + n))
					day += 366;
				else
					day += 365;
			}
		cout << day << endl;
	}
	return 0;
}
