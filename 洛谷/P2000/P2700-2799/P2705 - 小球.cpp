//若蓝红求各放自己的盒子里面分数比交换高，则各放各的，若交换后比较高，就尽量交换
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int r, b, c, d, e, sum;
    cin >> r >> b >> c >> d >> e;
    int mini = min(r, b);
    int maxi = max(r, b);
    if (2 * e < c + d)
        sum = r * c + b * d;
    else
        sum = mini * 2 * e + (maxi - mini) * (maxi == r ? c : d);
    cout << sum << endl;
    return 0;
}
