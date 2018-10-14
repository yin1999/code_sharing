#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;

bool panduan(float x, float y, float z, float e)
{
	bool flag = true;
	if ((abs(fmod(x, 60) / 5 - z) >= e / 30 && abs(fmod(x, 60) / 5 - fmod(y, 60) / 5) > e / 30 && abs(fmod(y, 60) / 5 - z) >= e / 30) == false)
		flag = false;
	if ((12 - abs(fmod(x, 60) / 5 - z) >= e / 30 && 12 - abs(fmod(x, 60) / 5 - fmod(y, 60) / 5) > e / 30 && 12 - abs(fmod(y, 60) / 5 - z) >= e / 30) == false)
		flag = false;
	return flag;
}
int main()
{
	float n;
	while (cin>>n)
	{
		float a = 0, b = 0, c = 0, i=0;
		if (n == 0)
			cout << "100.000" << endl;
		else if (n >= 120)
			cout << "0.000" << endl;
		else if (n == -1)
			break;
		for (; c <= 12;)
		{
			if (panduan(a, b, c, n))
				i++;
			a++;
			b = a / 60;
			c = a / 3600;
		}
		cout << fixed << setprecision(3) << i / (12 * 3600) * 100 << endl;
	}
	return 0;
}
