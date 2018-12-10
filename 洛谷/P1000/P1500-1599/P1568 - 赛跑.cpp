//思想，一分钟一分钟累加距离，若一方与另一方的领先状态发生改变，则改变次数加一，同时记录领先状态
#include <iostream>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n, m, sum = 0, i, k;
	int shv[1000], sht[1000], kcv[1000], kct[1000];
	bool flag;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> shv[i] >> sht[i];
	for (i = 0; i < m; i++)
		cin >> kcv[i] >> kct[i];
	int length_sh = 0, length_kc = 0;
	i = 0;
	k = 0;
	flag = cmp(shv[0], kcv[0]);   //初始化flag，一开始并没有状态变化（一开始谁快就谁领先）
	while (i != n && k != m)
	{
		length_sh += shv[i];
		length_kc += kcv[k];
		if ((--sht[i]) == 0)   //当次数维持状态的时间为0时，需要改变到下一状态
			i++;
		if ((--kct[k]) == 0)
			k++;
		if (flag != cmp(length_sh, length_kc))
		{
			flag = !flag;    //只需取反即可（状态只有两种情况，sh领先或者落后）
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
