#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		if (x || y)     //判断是否为输入两个0，若是，则break，不是，则执行程序
		{
			bool flag = true;    //标记是否都为素数，初始化为true
			for (; x <= y && flag; x++)     //循环语句，若已经出现了非素数，则跳出循环
			{
				int sum = x * x + x + 41;
        
				for (int i = 2; i < sqrt(sum) && flag; i++)   //判断素数算法，非素数则将flag赋值为false，同时跳出此循环
				{
					if (sum % i == 0)
						flag = false;
				}
			}
			if (flag)
				cout << "OK" << endl;
			else
				cout << "Sorry" << endl;
		}
		else
			break;
	}
	return 0;
}
