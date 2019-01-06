#include <iostream>
using namespace std;

int main()
{
	int n, k;
	bool t = false;
	cin >> n >> k;
	bool *flag = new bool[n + 1];
	int i, j;
	for (i = 2; i <= n; i++)
		flag[i] = true;
    
	for (i = 2; i <= n / 2; i++)    //线性筛法筛出素数
	{
		if (flag[i])
		{
			for (j = 2 * i; j <= n; j += i)
				flag[j] = false;
		}
	}
  
	for (i = 2; i <= n - k; i++)
	{
		if (flag[i] && flag[i + k])
		{
			cout << i << ' ' << i + k << endl;
			t = true;
		}
	}
  
	if (t == false)                //若没有符合条件的素数对，输出 empty
		cout << "empty" << endl;
    
	return 0;
}
