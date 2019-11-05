/**
 * 基数排序二维数组疯狂使用空间版
 * 方便理解基数排序中的桶
 */
#include <iostream>
#include <string.h>
using namespace std;

#define MaxArrayLength 1000

int tmp[10][MaxArrayLength];   //十个桶，分别是tmp[0], tmp[1]..., tmp[9]
int array[MaxArrayLength];
int count[10] = {}; //记录每一个桶中都有多少数字

int main()
{
    int n, maxNum = 0x7ffffff + 1; //最大负数
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        if (array[i] > maxNum)
        {
            maxNum = array[i];
        }
    }
    int maxBit = 0, k, i, j, index;
    int radix = 1; //位数
    while (maxNum) //计算当前最大数的位数
    {
        maxBit++;
        maxNum /= 10;
    }
    for (i = 1; i <= maxBit; i++) //由个位向最高位遍历
    {
        memset(count, 0, sizeof(count)); //清空计数器
        for (j = 0; j < n; j++)          //将数放进桶中
        {
            k = array[j] / radix % 10;   //取出当前位是几
            tmp[k][count[k]] = array[j]; //将该数放进桶中
            count[k]++;
        }
        k = 0;
        j = 0;
        index = 0;     //用于遍历桶中的所有数字
        while (k < 10) //将桶中的数放回数组
        {
            if (index >= count[k]) //取出桶中的所有数字后，选择下一个桶
            {
                k++;
                index = 0;
                continue;          //确保下一个桶不为空
            }
            array[j] = tmp[k][index];
            j++;
            index++;
        }
        radix *= 10; //位数进一
    }
    for (i = 1; i < n; i++) //验证排序是否正确，可以改成输出整个数组
    {
        if (array[i] < array[i - 1])
        {
            cout << "error!\n";
            return -1;
        }
    }
    return 0;
}
