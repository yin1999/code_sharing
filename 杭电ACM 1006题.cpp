//原题链接http://acm.hdu.edu.cn/showproblem.php?pid=1006
//谢谢大佬的帮助
#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;

bool panduan(float x, float y, float z, float e)    //分别输入秒，分，时，角度进行判断，若三个指针两两间的角度大于e，则return 1.
{
	if (abs(fmod(x,60)/5 - z) >= e / 30 && abs(fmod(x,60)/5 -fmod(y,60)/5) > e / 30 && abs(fmod(y,60)/5 - z) >= e / 30)
		return(1);
	else
		return(0);
}
int main()
{
	float n;
	while (cin>>n)     //输入间隔角度n
	{
		float a = 0, b = 0, c = 0, i=0;   //初始化秒a，分b，时c为0，初始化计数i=0.
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
		cout << fixed << setprecision(3) << i / (12 * 3600) * 100 << endl;    //输出保留3位小数的百分制结果
	}
	return 0;
}
