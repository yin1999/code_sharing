#include <iostream>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    int a[10] = {0};
    for(long long i = n; i <= m; i++)   //计算每一个数字中一个数字出现的次数
    {
        long long j = i;
        while(j)
        {
            a[j % 10]++;
            j /= 10;
        }
    }
    for(int i = 0; i < 9; i++)
        cout << a[i] << " ";
    cout << a[9] <<endl;
    return 0;
}
