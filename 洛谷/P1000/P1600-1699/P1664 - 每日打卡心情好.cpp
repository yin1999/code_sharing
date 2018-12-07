#include <iostream>
using namespace std;

int day_point(int day)
{
    if (day == 1 || day == 2)
        return 1;
    if (day < 7)
        return 2;
    if (day < 30)
        return 3;
    if (day < 120)
        return 4;
    if (day < 365)
        return 5;
    return 6;
}

int main()
{
    int n, temp, day_drop = 0;   //记录一共几天，是否签到，连续未签到天数
    int sumday = 0;
    int point = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp)
        {
            if (day_drop)
            {
                sumday -= 1 << --day_drop;   //按位进day_drop - 1位
                if (sumday < 0)
                    sumday = 0;
                day_drop = 0;
            }
            sumday++;
            point += day_point(sumday);
        }
        else
            day_drop++;
    }
    cout << point << endl;
    return 0;
}
