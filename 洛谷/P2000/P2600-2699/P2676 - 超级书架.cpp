//因为牛的数量多，而身高的数量级相对小很多，所以使用桶排，将相应身高的牛的数量储存起来，再从身高最高的向下取，这样取出来的数量最少
#include<iostream>
using namespace std;


int main()
{
	int n, H_i[10001] = { 0 }, count1 = 0, temp, i;
	long long b;
	cin >> n >> b;
	for (i = 0; i < n; i++)
	{
		cin >> temp;
		H_i[temp]++;
	}
	i = 10000;
	while (b > 0)
	{
		if (H_i[i] == 0)
		{
			i--;
			continue;
		}
		b -= i;
		H_i[i]--;
		count1++;
	}
	cout << count1 << endl;
	return 0;
}
