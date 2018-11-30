//这题很水
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int kw;
    double sum = 0;
    cin >> kw;
    if(kw <= 150)
        sum += kw * 0.4463;
    else
    {
        sum += 150 * 0.4463;
        kw -= 150;
        if(kw <= 250)
            sum += kw * 0.4663;
        else
        {
            sum += 250 * 0.4663;
            kw -= 250;
            sum += kw * 0.5663;
        }
    }
    cout << fixed << setprecision(1) << sum << endl;
    return 0;
}
