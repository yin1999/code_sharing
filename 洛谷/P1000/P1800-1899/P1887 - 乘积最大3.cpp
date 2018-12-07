//将一个数拆解成m个数的和，要使这m个数的乘积最大，只要让它们尽量地靠近，所以取两个数，一个是n / m，一个是n / m + 1，n / m + 1的个数就是n % m
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int remain = n % m;
    int d = n / m;
    for (int i = remain; i < m; i++)
        cout << d << ' ';
    for (int i = 0; i < remain; i++)
        cout << d + 1 << ' ';
    cout << endl;
    return 0;
}
