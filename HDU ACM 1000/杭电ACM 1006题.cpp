#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;

double max(double a, double b, double c)
{
	double max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;
}

double min(double a, double b, double c)
{
	double min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}


int main()
{
	double s = 6, m = 0.1, h = 1.0 / 120;     //定义角速度并赋值
	double s_m = 5.9, s_h = s - h, m_h = m - h;    //角速度之差

	double Ts_m = 360.0 / s_m;      //各循环的周期
	double Ts_h = 360.0 / s_h;
	double Tm_h = 360.0 / m_h;

	double D;       //分离角度D
	while (cin >> D)
	{
		double SATs_m, SATs_h, SATm_h, Us_m, Us_h, Um_h;   //SAT为满足条件计时，U为不满足条件计时
		double i, j, k;  //计数（角度）
		double begin, end;
		double total = 0;

		if (D == -1)
			break;

		SATs_m = D / s_m;       //计算第一次满足条件的时间，就是两针分离D度所需要的时间
		SATs_h = D / s_h;
		SATm_h = D / m_h;

		Us_m = (360 - D) / s_m;      //计算第一次不满足条件的时间,就是两针分离了360-D度所需要的时间(之后就不符合了)
		Us_h = (360 - D) / s_h;
		Um_h = (360 - D) / m_h;

		for (i = 0; i < 43200.0; i += Tm_h)   //i记录秒针角度，递增使用分针与时针转的角度差周期，较少枚举计算量
		{
			for (j = 0; j < 43200.0; j += Ts_h)   //j记录秒针角度，递增使用秒针与时针转的角度差周期
			{
				if (j + SATs_h > i + Um_h)
					break;
				if (i + SATm_h > j + Us_h)
					continue;
				for (k = 0; k < 43200.0; k += Ts_m)     //k记录秒针角度，递增使用秒针与分针转的角度差周期
				{
					if (k + SATs_m > i + Um_h || k + SATs_m > j + Us_h)
						break;
					if (i + SATm_h > k + Us_m || j + SATs_h > k + Us_m)
						continue;

					begin = max(i + SATm_h, j + SATs_h, k + SATs_m);  //在这三个时间段刚好完成分离D度，所以取最大值才能保证全都分离D以上
					end = min(i + Um_h, j + Us_h, k + Us_m);     //在这三个时间段刚好完成合并n度，所以取最小值才能保证全都未合并到D以内
					if (end > begin)
						total += (end - begin);
				}
			}
		}
		cout << fixed << setprecision(3) << total / 432.0 << endl;    //total/432.0  <--total*100.0/43200.0
	}
	return 0;
}
