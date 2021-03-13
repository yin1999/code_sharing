#include<iostream>
using namespace std;

int main()
{
	int N;
	while (cin >> N)
	{
		int a[31] = { 0 }, b[31] = { 0 };   //分别储存上一行的数组与下一行的计算结果
		a[1] = 1;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (j == 1)    //每行第一个是1
					b[j] = a[j];
				else if(j<i)
					b[j] = a[j - 1] + a[j];
				else    //每行最后一个是1
					b[j] = a[j - 1];
          
				if (j < i)    //控制输出格式
					cout << b[j] << " ";
				else
					cout << b[j] << endl;
			}
      
			for (int k = 1; k <= i; k++)
				a[k] = b[k];   //将计算结果赋给a数组，从而进行下一层的计算
		}
		cout << endl;
	}
	return 0;
}
