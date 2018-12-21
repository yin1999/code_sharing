#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int n, d, temp;
    int i, j;
    cin >> n >> d;
    int *a = new int[n];
    for (i = 0; i < n; i++)   //输入所有数据
        cin >> a[i];
        
    sort(a, a + n, cmp);    //从小到大排序
    
    int count1 = 0, maxpos = 0;    //分别记录总对数和对于当前奶牛，它最远能和下标为多少的奶牛交流（排序后），减少循环比较次数
    for (i = 0; i < n - 1; i++)
    {
        count1 += maxpos - i;   //到下一头牛以后，它肯定能和（到上一头牛为止，它所能向右交流到的）牛交流
        
        for (j = maxpos + 1; j < n; j++)
        {
            if (a[j] - a[i] <= d)
                count1++;
            else
            {
                maxpos = j - 1;
                break;
            }
        }
        if (j == n)
            maxpos = j - 1;
    }
    
    cout << count1 << endl;
    
    delete[] a;
    return 0;
}
