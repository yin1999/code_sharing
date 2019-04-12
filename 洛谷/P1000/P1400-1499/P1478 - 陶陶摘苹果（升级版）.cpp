#include <iostream>
using namespace std;

int main()
{
    int n, s, a, b, xi, yi;
    cin >> n >> s >> a >> b;
    int max_length = a + b;
    int A[101] = { 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> xi >> yi;
        if (xi <= max_length)
        {
            A[yi]++;
        }
    }
    int j = 0;
    for (int i = 0; i <= 100;)
    {
        if (A[i] == 0)
        {
            i++;
            continue;
        }
        if (i <= s)
        {
            s -= i;
            A[i]--;
            j++;
        }
        else
            break;
    }
    cout << j << endl;
    return 0;
}
