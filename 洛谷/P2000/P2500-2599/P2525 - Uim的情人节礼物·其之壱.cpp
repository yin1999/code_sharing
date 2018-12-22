/*
思路：从后向前看，当前一数大于当前前面的数的时候，这个排列是以此往后的字典序最小排列，没法找出更小的了
例：3 1 2 4， 在3以后的所有数，此状态1 2 4是字典序最小排列
要使字典序减少1， 只能当前面的一个数比后一个数大时才能找到（参考get_unnum函数）
从后向前找到该位置时，需要再从这个数向后找，找到与当前数差1的数，交换其位置（如上面举例中的3和2），然后将当前数后的所有数从大到小排列
可能讲得不是很清楚，需要好好理解一下
#include <iostream>
using namespace std;

int num[10];

void SORT(int left, int right)    //排序
{
    int i, j, key;
    for (i = left + 1; i <= right; i++)
    {
        if (num[left] == num[i] + 1)
        {
            num[left]--;
            num[i]++;
            break;
        }
    }
    for (i = left + 2; i <= right; i++)
    {
        key = num[i];
        for (j = i - 1; j > left; j--)
        {
            if (num[j] < key)
                num[j + 1] = num[j];
            else
                break;
        }
        num[j + 1] = key;
    }
    return;
}

int get_unnum(int length)    //找出从后向前的第一个逆序的数（逆序的数仍为从前向后的情况）
{
    int por_num = num[length - 1], i;
    for (i = length - 2; i >= 0; i--)
    {
        if (num[i] > por_num)
            break;
        por_num = num[i];
    }
    return i;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    int posi = get_unnum(n);
    if (posi != -1)   //当得到的位置是-1时，说明当前状态没有逆序的数，字典序最小
    {
        SORT(posi, n - 1);
        for (int i = 0; i < n - 1; i++)
            cout << num[i] << ' ';    //输出
        cout << num[n - 1] << endl;
    }
    else
        cout << "ERROR" << endl;    //输出
    return 0;
}
