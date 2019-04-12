/*首先，陶陶能摘到的苹果要满足，其高度小于陶陶伸直手臂加上凳子的最大高度，所以，可以在输入数据的时候进行筛选，只保留
能够到的苹果的获取所需要的体力。
而因为所需体力的范围比较小(0-100)可以使用计数排序的方法，统计每一个所需体力的苹果个数。然后再进行计数就可以了
*/
#include <iostream>
using namespace std;

int main()
{
    int n, s, a, b, xi, yi;
    cin >> n >> s >> a >> b;
    int max_length = a + b;
    int A[101] = { 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> xi >> yi;
        if (xi <= max_length)
        {
            A[yi]++;
        }
    }
    int j = 0;
    for (int i = 0; i <= 100;)
    {
        if (A[i] == 0)
        {
            i++;
            continue;
        }
        if (i <= s)
        {
            s -= i;
            A[i]--;
            j++;
        }
        else
            break;
    }
    cout << j << endl;
    return 0;
}
