//解题偷懒了，有更简单的方法（结果为n+(n-1)/(k-1) ）
#include<iostream>
using namespace std;

int main()
{
    int n, k, temp;
    cin >> n >> k;
    long long sum = n;
    while(n >= k)
    {
        temp = n / k;
        n = temp + n % k;
        sum += temp;
    }
    cout << sum << endl;
    return 0;
}
