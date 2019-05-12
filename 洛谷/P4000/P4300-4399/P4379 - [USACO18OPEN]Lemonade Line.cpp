//对输入的数组从大到小排序，然后依次向后比较其下标和其值的大小，当下标大于值的时候，说明这头奶牛及以后的奶牛都不会排队了，这是最优解
#include <iostream>
#include <algorithm>
using namespace std;

inline bool cmp(unsigned left, unsigned right)
{
    return left > right;
}


int main()
{
    unsigned n;
    cin >> n;
    unsigned* array = new unsigned[n];
    for (unsigned i = 0; i < n; i++)
        cin >> array[i];
    sort(array, array + n, cmp);
    unsigned i = 0;
    for (; i < n; i++)
    {
        if (array[i] < i)
            break;
    }
    cout << i << endl;
    return 0;
}
