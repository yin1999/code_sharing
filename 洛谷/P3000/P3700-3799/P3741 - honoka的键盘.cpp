//题目讲解，换一个字母，最多再加一共VK
//我的思路是：把VK先找出来，找到则计数，并把相应的位置用空字符代替
//在找的过程中，如果碰到两个字符全是K，则计数
//在第二遍寻找VV时（在没有碰到KK计数的情况下），只要确定是否有两个V连在一起即可
#include <iostream>
using namespace std;

int main()
{
    int n, count1 = 0;
    char str[101];
    bool flag = true;   //用来记录是否有字母被替换
    cin >> n >> str;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == 'V' && str[i + 1] == 'K')
        {
            str[i] = 0;
            str[i + 1] = 0;
            count1++;
            i++;
        }
        else if(flag && str[i + 1] == 'K')
        {
            count1++;
            flag = false;
            i++;
        }
    }
    if(flag)
        for (int i = 0; i < n - 1; i++)
        {
            if (str[i] == 'V' && str[i + 1] == 'V')
            {
                count1++;
                break;
            }
        }
    cout << count1 << endl;
    return 0;
}
