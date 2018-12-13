//这题有点小问题，津津的不高兴度不会保留到第二天，从它给的例子是可以看出来的
//所以，挺简单的
#include <iostream>
using namespace std;

int main()
{
    int x, y, sum = 8, day = 0;
    for (int i = 1; i <= 7; i++)
    {
        cin >> x >> y;
        if (sum < x + y)
        {
            sum = x + y;
            day = i;
        }
    }
    cout << day << endl;
    return 0;
}
