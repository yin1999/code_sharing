//先手必赢问题
/*
当 m 与 n + 1取余等于0的时候，先手必输
因为，无论先手如何取球，只要后手取球数与先手的和为n + 1，先手必然无法获胜
（这样保证了在先手最后一次取球前，球的总数为 n + 1先手怎么取，都是后手赢）

当然，先手也只有这样会输，因为先手可以在总球数不为n + 1的倍数的情况下，把
这样的情况转嫁给后手（第一次取总球数与n + 1的余数），后手会陷入必输的情况
*/
#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	while (cin >> n >> m)
	{
		if (m % (n + 1) == 0)
			cout << "You are loser";
		else
		{
			if (n > m)    //特殊情况（其实n == m也是，把它放到else中了）
			{
				cout << m;
				for (int i = m + 1; i <= n; i++)
					cout << ' ' << i;
			}
			else
				cout << m % (n + 1);
		}
		cout << endl;
	}
	return 0;
}
