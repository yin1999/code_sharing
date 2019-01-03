#include <iostream>
using namespace std;

int ans[10];
int count1 = 0;

void dfs(int remain, int num, bool flag)
{
    if (num == 9)
    {
		if (remain <= 3)
		{
        	if (flag)
        	{
            	for (int i = 0; i < 9; i++)
                	cout << ans[i] << ' ';
            	cout << remain << endl;
        	}
        	else
            	count1++;
		}
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        if (i >= remain)
            return;
        ans[num] = i;
        dfs(remain - i, num + 1, flag);
    }
}

int main()
{
    int n;
    cin >> n;
    if (n >= 10 && n <= 30)
    {
        dfs(n, 0, false);          //统计一共有多少个满足条件的数列
        cout << count1 << endl;
        dfs(n, 0, true);           //输出
    }
    else
        cout << 0 << endl;
    return 0;
}
