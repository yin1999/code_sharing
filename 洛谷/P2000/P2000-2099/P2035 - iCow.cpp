#include <iostream>
using namespace std;


int main()
{
    int n, t, i, m;
    cin >> n >> t;
    int* array = new int[t];
    for (i = 0; i < n; i++)
        cin >> array[i];
    int Max, c;
    while (t--)
    {
        Max = *array;
        i = -1;
        m = 0;
        while (++i < n)          //找出最大权值，储存到m中
        {
            if (array[i] > Max)
            {
                Max = array[i];
                m = i;
            }
        }
        cout << m + 1 << '\n';    //输出歌曲编号
        c = array[m] / (n - 1);
        array[m] %= n - 1;
        //************************分配权值开始
        if (c)
        {
            i = -1;
            while (++i != m)
                array[i] += c;
            while (++i != n)
                array[i] += c;
        }
        i = 0;
        while (array[m])
        {
            if (i == m)
                i++;
            array[i]++;
            array[m]--;
            i++;
        }
        //************************分配权值结束
    }
    delete[] array;
    return 0;
}
