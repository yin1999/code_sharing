//根据题意，我们可以将猫粮看作现金，JavaBean看作商品，老鼠是拿现金取买Java豆的，商品价格越低，买到的商品越多
#include<iostream>
#include<iomanip>
#define max 10000000

using namespace std;
double buy(int money, int store_own, int sum_price);   //自定义函数声明，在底下


int main()
{
	int M, N;
	int Food[1000], JavaBean[1000];  //储存所需catfood（金钱），JavaBean（商品）
	double average[1000];   //储存平均价格
	while (cin >> M >> N)
	{
		if (N == -1 && M == -1)   //是否结束输入判断
			break;
		double sum = 0;   //储存购买总量，初始化为0
		for (int i = 0; i < N; i++)
		{
			cin >> JavaBean[i] >> Food[i];
			average[i] = Food[i] * 1.0 / JavaBean[i];
		}
		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			for (int k = 1; k < N; k++)    //找出第一次购买或这接下去几次的购买中，均价最低的房间
			{
				if (average[temp] > average[k])
					temp = k;
			}
      
			if (average[temp] == max)    //此函数用于判断是否将所有房间中的Bean买完，若买完，则会有所有房间内食物的均价都为max的结果
				break;
			sum += buy(M, JavaBean[temp], Food[temp]);
			M -= Food[temp];   //购买后剩余cat food量（假装能购买下房间中所有的Bean）
			if (M <= 0)    //小于0则表明钱已经花完了
				break;
			average[temp] = max;    //给购买过的房间均价赋成max，不会对下面几次找均价最低商品造成影响
		}
		cout << fixed << setprecision(3) << sum << endl;
	}
	return 0;
}


double buy(int money, int store_own, int sum_price)    //输出本次购买量，输入值依次为拥有的cat food，房间内Bean的存量，所需cat food量
{
	if (sum_price < money)
		return store_own;
	else
		return store_own * 1.0 / sum_price * money;
}
