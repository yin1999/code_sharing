#include <iostream>
using namespace std;

int main()
{
    int x, n;
    long long sum = 1;   //使用int会超范围
    cin >> x >> n;
    while(n--)
    {
        sum = sum * x + sum;
    }
    cout << sum << endl;
    return 0;
}
