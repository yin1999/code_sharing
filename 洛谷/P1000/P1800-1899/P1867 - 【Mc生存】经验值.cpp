#include <iostream>
using namespace std;

int main()
{
	int n;
	double sum = 0, temp_life, temp_exp, life = 10;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp_life >> temp_exp;
		life -= temp_life;
		if (life <= 0)    //如果生命值小于等于0，就死了
			break;
		else if (life > 10)    //如果生命大于10了，给它赋10
			life = 10;
		sum += temp_exp;    //经验值增加
	}
	int level = 0;    //初始等级就是0，题目骗人了，看示例输入和输出结果！！！
	int exp_need = 1;
	while (sum > exp_need)
	{
		sum -= exp_need;
		level++;
		exp_need <<= 1;      //与exp_need *= 2效果相同，按位处理
	}
	cout << level << ' ' << sum << endl;
	return 0;
}
