//排序再计算
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int n, i;
    int sum = 0;
    cin >> n;
    int *a = new int[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    int forward = a[0], count1 = 1;
    for (i = 1; i < n; i++)
    {
        if (a[i] == forward)
            count1++;
        else
        {
            sum += 5 + count1;
            forward = a[i];
            count1 = 1;
        }
    }
    sum += a[n - 1] * 10 + count1 + 5;
    cout << sum << endl;
    delete[] a;
    return 0;
}
