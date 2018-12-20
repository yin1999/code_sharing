//无论如何，两人最后总能把石头全部取完，所以判断总和的奇偶性即可
#include <iostream>
using namespace std;

int main()
{
    int n, temp, sum = 0;
    cin >> n;
    while (n--)
    {
        cin >> temp;
        sum += temp;
    }
    if ((sum & 1) == 1)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
    return 0;
}
