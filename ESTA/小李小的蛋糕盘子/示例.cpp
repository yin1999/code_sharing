#include<iostream>
using namespace std;

int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		int s, m, val[10], w[10], sum_val = 0;   //val储存蛋糕单价，w储存蛋糕质量，sum_val储存装到盘子中的蛋糕总价值
		cin >> s >> m;   //分别输入蛋糕种类和盘子能装的蛋糕质量
		for (int i = 0; i < s; i++)
			cin >> val[i] >> w[i];
		int space = s;   //防止出现蛋糕用完还没有装满盘子
		while (m && space--)   //每次循环让space自减，表示蛋糕总数少了1
		{
			int temp = 0;
			for (int i = 1; i < s; i++)
			{
				if (val[i] > val[temp])
					temp = i;
			}
			if (m >= w[temp]) 
			{
				m -= w[temp];   //不能忘记减掉能装的蛋糕质量
				sum_val += val[temp] * w[temp];
				val[temp] = 0;    //用完某种蛋糕后让它的价格变成0，表示它被用完了，不会被重复计价
			}
			else
			{
				sum_val += val[temp] * m;
				m = 0;
			}
		}
		cout << sum_val << endl;
	}
	return 0;
}
