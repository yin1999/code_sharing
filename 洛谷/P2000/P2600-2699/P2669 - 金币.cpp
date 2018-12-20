#include <iostream>
using namespace std;

int main()
{
    int k, ac = 1, sum_coin = 0;   //记录剩余天数，应得金币数量/连续天数，获得金币总数
    cin >> k;
    while (k >= ac)
    {
        sum_coin += ac * ac;
        k -= ac;
        ac++;
    }
    sum_coin += k * ac;
    cout << sum_coin << endl;
    return 0;
}
