//简单的深搜题
/*
这题需要把草皮分成4块，我们就使用for循环枚举每一块地可以有的大小
从0到剩余可用地皮的算术平方根
一层一层递归，最多到第4层，若到第四层的总面积等于输入的n时，则找到一种情况
到在前几层递归就找到一种情况时，不需要继续递归了（后面几块地皮只能取面积为0）
需要回溯！！！
*/
#include <iostream>
#include <cmath>
using namespace std;

int sum = 0, count1 = 0, n;

void dfs(int temp, int num)
{
    for (int i = 0; i <= sqrt(temp); i++)
    {
        sum += i * i;
        if (sum == n)    //当面积已经达到输入值时，不需要递归了，后面有地块的话，面积也只能是零
            count1++;
        else if (num < 3)   //当num >= 3 时，已经超过了4块（不需要递归了！！）
            dfs(n - sum, num + 1);   //继续递归
        sum -= i * i;    //回溯
    }
}

int main()
{
    cin >> n;
    dfs(n, 0);
    cout << count1 << endl;
    return 0;
}
