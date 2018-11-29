#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e, f;
    f = d - b;
    e = c - a;
    if(f < 0)   //注意分相减小于0的情况
    {
        f += 60;
        e--;
    }
    cout << e << " " << f << endl;
}
