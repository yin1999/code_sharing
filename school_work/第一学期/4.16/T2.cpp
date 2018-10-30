#include<iostream>
#include<cmath>
using namespace std;

void null()
{
	cout << "你输入的方程无实数解" << endl;
}

void onex(float a, float b)
{
	cout << "它的两个相同实数解为 " << -b / (a * 2) << endl;
}

void twox(float a, float b, float c)
{
	cout << "它的两个不同实数解为 " << (-b + sqrt(b*b - 4 * a*c) / (2 * a)) << "  " << (-b - sqrt(b*b - 4 * a*c) / (2 * a)) << endl;
}

int main()
{
	float a, b, c, sum;
	cout << "请依次输入一个二次方程的二次项，一次项，常数项" << endl;
	cout << "输入三个0则终止本程序" << endl;
	while (cin >> a >> b >> c)
	{
		if (!(a || b || c))
			break;
		sum = b * b - 4 * a*c;
		if (!sum)
			onex(a, b);
		else if (sum < 0)
			null();
		else
			twox(a, b, c);
		cout << "等待再次输入" << endl;
	}
	return 0;
}
