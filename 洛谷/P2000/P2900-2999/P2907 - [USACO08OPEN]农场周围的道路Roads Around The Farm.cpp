//递归调用就很简单了，只有当当前总数减去差值的结果是偶数时，牛群才能分成两群（注意，差值不能为零）
#include <iostream>
using namespace std;

int count1 = 0, k;
void dfs(int sum)
{
    if ((sum - k) % 2 == 0 && sum > k)
    {
        dfs((sum - k) / 2 + k);
        dfs((sum - k) / 2);
    }
    else
        count1++;
}

int main()
{
    int n;
    cin >> n >> k;
    dfs(n);
    cout << count1 << endl;
    return 0;
}
