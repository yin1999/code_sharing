#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int mins = 0, temp;    //temp储存当前连续数组的和，mins储存最小连续数组的和
    cin >> n >> m;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        mins += a[i];
    temp = mins;
    for (int i = m; i < n; i++)
    {
        temp -= a[i - m];
        temp += a[i];
        if (temp < mins)
            mins = temp;
    }
    cout << mins << endl;
    delete[] a;
    return 0;
}
