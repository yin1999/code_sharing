#include<iostream>
using namespace std;

int main()
{
    int n, sum = 0, sum_temp = 0;
    int temp1, temp2;
    cin >> n;
    while(n--)
    {
        cin >> temp1 >> temp2;
        sum_temp += temp1 + temp2 - 8;
        sum += sum_temp;
    }
    cout << sum << endl;
    return 0;
}
