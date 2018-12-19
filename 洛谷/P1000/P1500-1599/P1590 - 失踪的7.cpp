//事先说明，因为题目中的数据范围比较大，到了2的32次 - 1， 所以int是不够用的，需要使用long long int/ unsigned int 如使用unsigned int
//请将下列代码中的long long换成unsigned int
/*
思路，递归处理，当前数应有的大小是最高位（非7和零） * pow(9, 最高为位数 - 1)，与其剩余位数（处理次高位，层层递归）的和
例：比如201，则其大小为2 * 9 * 9 + 0 * 9 + 2（个位有0, 1） - 1（剪掉0）.
*/
#include <iostream>
#include <cmath>
using namespace std;

int n, length;
long long sum, m, count1, temp;

void dfs(int length1, long long sum)
{
    if (length1)    //当前位不是个位的情况（需要递归处理次位）
    {
        int c;
        long long t, remain;
        t = (long long)pow(10, length1);
        remain = sum % t;
        sum = sum - remain;
        c = sum / t;
        if (c != 7)
        {
            dfs(length1 - 1, remain);   //递归处理次位
        }
        if (c > 7)
            count1 += (int)pow(9, length1) * (c - 1);
        else if(c < 7 && c != 0)
            count1 += (int)pow(9, length1) * c;
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            if (i <= sum && i != 7)
                count1++;
        }
    }
}
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> m;
        length = 0;
        temp = m;
        count1 = 0;
        while (temp)
        {
            length++;
            temp /= 10;
        }
        dfs(length - 1, m);
        cout << count1 - 1 << endl;
    }
    return 0;
}
