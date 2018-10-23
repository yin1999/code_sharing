#include<iostream>
#include<cmath>
using namespace std;

int size(int a)    //读取数的长度，并返回这个值
{
	int c = 0;
	while (a)
	{
		a /= 10;
		c++;
	}
	return c;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		bool flag = false;     //标记是否存在水仙花数，初始化为false
    
    if (n < m)   //判断输入两数的大小，进行排序（n小，m大）
    {
        n += m;
        m = n - m;
        n -= m;
    }
    
		for (int i = n; i <= m; i++)
		{
			int sum = 0, temp = i;    //定义sum用于求和，temp用于零时储存当前数
			for (; temp > 0;)
			{
				sum = sum + pow(temp % 10, size(i));
				temp /= 10;
			}
			
      if (sum == i)
			{
				if (flag)    //判断是否为当前数组的第一次输出水仙花数，第一个不输出空格
					cout << " " << sum;
				else
					cout << sum;
				flag = true;
			}
		}
		if (!flag)    //若不存在水仙花数，则输出“no”
			cout << "no" << endl;
		else 
			cout << endl;
	}
	return 0;
}
