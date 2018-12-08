/*
将技能消耗的法力值分类：1.大于0 2.等于0 3.小于0
1. 怪兽的生命值小于等于(法力值 / 技能消耗法力值 * 一次使用技能造成的伤害) 则可以使用（造成伤害大于0）
2. 只要造成伤害大于0即可
3. 造成伤害大于0
*/
#include <iostream>
using namespace std;

int main()
{
    int k, m, n, a, b;
    cin >> k >> m >> n;
    int *c = new int[m];
    int count1 = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (a <= 0)
        {
            if (b > 0)
                c[count1++] = i;
        }
        else if (a > 0)
        {
            if( n <= k / a * b)
            c[count1++] = i;
        }
    }
    if (count1)
    {
        for (int i = 0; i < count1; i++)
            cout << c[i] + 1 << ' ';
    }
    else
        cout << -1;
    cout << endl;
    delete[] c;
    return 0;
}
