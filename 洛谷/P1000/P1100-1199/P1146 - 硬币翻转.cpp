//要把n个硬币翻转过来（n为偶数）只要从第一个开始，每次只有那一个不动，翻转其它n - 1个，依次递增就可以把所有硬币翻转过来
#include <iostream>
using namespace std;

int main()
{
    int a[100] = { 0 };
    int n, i, j;
    cin >> n;
    cout << n << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
            a[j] = 1 - a[j];
        for (j = i + 1; j < n; j++)
            a[j] = 1 - a[j];
        for (j = 0; j < n; j++)
            cout << a[j];
        cout << endl; 
    }
    return 0;
}
