//逆序数问题，当一个数前面有n个数比它大时，它需要n次才能到它需要到的位置（全局考虑）
//可以使用冒泡排序验证
#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        for (int j = 0; j < i; j++)
        {
            if (b[j] > b[i])
                sum++;
        }
    }
    cout << sum << endl;
    delete[] b;
    return 0;
}
