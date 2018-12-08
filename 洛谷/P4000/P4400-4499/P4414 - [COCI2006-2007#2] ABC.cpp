#include <iostream>
using namespace std;

int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    if (a[0] > a[1])
        swap(a[0], a[1]);
    if (a[0] > a[2])
        swap(a[0], a[2]);
    if (a[1] > a[2])
        swap(a[1], a[2]);
    char str[4];
    cin >> str;
    for (int i = 0; i < 3; i++)
    {
        cout << a[(int)str[i] - 65] << ' ';
    }
    cout << endl;
    return 0;
}
