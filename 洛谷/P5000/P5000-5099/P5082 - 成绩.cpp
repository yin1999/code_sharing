//此题只要注意是小数就可以了
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, sum_all = 0, sum_xiaoben = 0;
    int temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        sum_all += temp;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        sum_xiaoben += temp;
    }
    cout << fixed << setprecision(6) << (1. * sum_all * 3 - sum_xiaoben * 2) / (sum_all - sum_xiaoben) << endl;
    return 0;
}
