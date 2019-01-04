#include <iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    k /= 364;
    for (int i = 100; i >= 0; i--)
    {
        if (i < k && (k - i) % 3 == 0)
        {
            cout << i << endl;
            cout << (k - i) / 3 << endl;
            return 0;
        }
    }
    return 0;
}
