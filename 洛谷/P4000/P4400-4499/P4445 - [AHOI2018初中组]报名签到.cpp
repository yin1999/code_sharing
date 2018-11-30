//思路，找出两个人中间对距离要求比较大的那个就是两人需要保持的最小距离，不要忘记考虑只有一个人的情况！
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int t1, t2;  //t1储存前一个人对距离的要求，t2储存后一个人对距离的要求，找出较大值求和
    long long sum = 0;
    cin >> t1;
    while(--n)
    {
        cin >> t2;
        sum += max(t1, t2);
        t1 = t2;
    }
    cout << sum << endl;
    return 0;
}
