#include <iostream>
using namespace std;

bool find(int *a, int length, int key)   //二分法查找是否有该数
{
    int left = 0, right = length - 1, mid;
    while (left <= right)
    {
        mid = (right + left) / 2;
        if (a[mid] == key)
            return true;
        else if (a[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

int main()
{
    int n, num, temp, count1 = 1;
    int i, j;
    cin >> n >> num;
    int *a = new int[n];   //开辟空间储存数组
    if (a == 0)
        return 0;
    cin >> a[0];     //输入数组中第一个值
    for (i = 1; i < n; i++)
    {
        cin >> temp;       //输入数组元素
        if (find(a, count1, temp))   //若重复出现，则continue，继续下一个输入
            continue;
        for (j = count1 - 1; j >= 0; j--)    //若没有重复，则将其插入到原数组中
        {
            if (a[j] > temp)
                a[j + 1] = a[j];
            else
                break;
        }
        a[j + 1] = temp;
        count1++;
    }
    if (num <= count1)    //只有数组大小(去重后)小于需要的第n小的n才无法输出结果
        cout << a[num - 1] << endl;
    else
        cout << "NO RESULT" << endl;
    delete[] a;
    return 0;
}
