//先把价格从小到大排序，然后，确定农夫数量和草的数量，最低价格从那个价格刚好满足符合该价格的农夫数量小于等于草的数量
//然后只要结果向上加（一个梯度为刚好满足减少一个符合条件的农夫，而次低报价的农夫能接收的价格
#include <iostream>
using namespace std;

int main()
{
    int n, m, i, j, temp;
    int lowprice;
    cin >> n >> m;
    int *a = new int[m];
    if (a == 0)
        return 0;
    cin >> a[0];
    for (i = 1; i < m; i++)
    {
        cin >> temp;
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] > temp)
                a[j + 1] = a[j];
            else
                break;
        }
        a[j + 1] = temp;
    }
    int num = 0;
    if (n < m)
        num = m - n;
    int sum_temp = 0, sum = 0;
    for (; num < m; num++)
    {
        int t = a[num];
        sum_temp = (m - num) * t;
        if (sum < sum_temp)
        {
            lowprice = t;
            sum = sum_temp;
        }
    }
    cout << lowprice << ' ' << sum << endl;
    delete[] a;
    return 0;
}
