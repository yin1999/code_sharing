#include<iostream>
#include<cmath>
using namespace std;

bool prime(int n)   //判断是否为素数
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;   //若不是素数，直接return false，同时这个块函数终止
	}
	return true;   //若不能被2-sqrt(n)范围内的数整除，则为素数，return true
}

int main()
{
	int a[99], isprime[50], c = 0;  //a数组储存2-100内的数，isprime数组储存判断出来是素数，c用来给素数计数
	for (int i = 0; i < 99; i++)
		a[i] = i + 2;
	
	for (int j = 0; j < 99; j++)
	{
		if (a[j] && prime(a[j]))   //看下面的代码可知，当一个数被筛出非素数时，给它赋值为0，若为0则直接跳出if语句，若不是0则继续判断是否为素数
		{
			isprime[c] = a[j];   //为素数则储存到isprime中并给计数器“c”加1；
			c++;

			for (int k = 2; k*a[j] <= 100; k++)  //筛除接下去的非素数
				a[k*a[j] - 2] = 0;  //非素数赋0，数组a的下标与其储存是数据差2(看懂下标的意思!)
		}
	}
	for (int i = 0; i < c; i++)  //输出素数
		cout << isprime[i] << " ";
	cout << endl;
	return 0;
}
