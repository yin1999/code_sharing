//因为数据的范围很小，定义一个1001大小的数组，来标记1000以内的数是否出现过
#include <iostream>
using namespace std;

int main()
{
    int n, a[1001] = { 0 }, temp;
    int count1 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (a[temp] == 0)    //当此数没有出现过，则计数加一
        {
          count1++;
          a[temp] = 1;
        }
    }
    cout << count1 << endl;
    bool flag = false;
    for (int i = 0; i <= 1000; i++)
    {
        if (a[i])
        {
            if (flag)
                cout << ' ' << i;
            else
            {
                cout << i;
                flag = true;
            }
        }
    }
    cout << endl;
    return 0;
}
