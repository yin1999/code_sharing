//完全平方数的因子个数为奇数，才能变亮
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    for (long long i = 1; i <= (long long)sqrt(n); i++)
        cout << i * i << ' ';
    cout << endl;
    return 0;
}
