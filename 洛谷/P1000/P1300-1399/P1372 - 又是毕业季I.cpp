//最大公约数，当有n个人的时候，从中取k个，那么，里面k个人的最小公倍数就是n整除k
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    cout << n / k << endl;
    return 0;
}
