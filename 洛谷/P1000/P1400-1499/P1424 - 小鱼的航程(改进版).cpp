#include <iostream>
using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    int d = n / 7 * 5;
    int r = n % 7;
    if (r > 0)
    {
        if (r + x == 7 || x == 7)
            r -= 1;
        else if (r + x >= 8)
            r -= 2;
    }
    cout << (d + r) * 250 << endl;
    return 0;
}
