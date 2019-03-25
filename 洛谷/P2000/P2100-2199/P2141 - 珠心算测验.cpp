#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[110], n, i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);   //排序
	int temp = a[0];
	for (i = 1; i < n; i++)    //将所有重复出现的数都改成0，防止重复出现的数多次计入结果
	{
		if (a[i] == temp)
			a[i] = 0;
		else
			temp = a[i];
	}
	int _count = 0;
	bool flag;        //标记相应的数是否已经找到满足条件的例子，防止同一个数被重复计数
	for (i = 2; i < n; i++)
	{
		flag = true;
		if (a[i] == 0)
			continue;
		for (j = 0; j < i && flag; j++)
		{
			if (a[j] == 0)
				continue;
			for (k = 0; k < j && flag; k++)
			{
				if (a[k] == 0)
					continue;
				if (a[j] + a[k] == a[i])
				{
					_count++;
					flag = false;
				}
			}
		}
	}
	cout << _count << endl;
	return 0;
}
