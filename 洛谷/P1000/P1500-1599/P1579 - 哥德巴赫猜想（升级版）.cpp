#include <iostream>
#include <cmath>
using namespace std;

bool is_primer(int n)
{
    if (n == 2)
        return true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int i, j, k;
    if (is_primer(n - 4))
        cout << "2 2 " << n - 4 << endl;
    else
    {
        for (i = 3; i < n; i += 2)
        {
            if (!is_primer(i))
                continue;
            k = n - i;
            for (j = 3; j < k; j += 2)
            {
                if (!is_primer(j))
                    continue;
                if (is_primer(k - j))
                {
                    cout << i << ' ' << j << ' ' << k - j << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
