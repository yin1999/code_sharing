#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            a = b;
        cout << (a - 1) * 2 << endl;
    }
    return 0;
}
