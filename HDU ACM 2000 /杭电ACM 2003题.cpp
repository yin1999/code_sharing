#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	double num;    //测试发现，一定要double型。。。。
	while (cin >> num)
	{
		cout << fixed << setprecision(2) << abs(num) << endl;
	}
}
