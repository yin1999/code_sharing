//价格乘以十再计算就很简单了
#include <iostream>
#define price 19
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    a = a * 10 + b;
    cout << a / price << endl;
    return 0;
}
