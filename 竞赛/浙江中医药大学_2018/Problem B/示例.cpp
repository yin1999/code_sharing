#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	bool flag;
	while (cin >> n >> m)
	{
		flag = false;
		for (i = 1; i <= n; i++)
		{
			if (i < m && i + n >= m)
				continue;
			if (flag)
				cout << ' ' << i;
			else
			{
				cout << i;
				flag = true;
			}
		}
		if (flag == false)
			cout << "You are loser";
		cout << endl;
	}
	return 0;
}
