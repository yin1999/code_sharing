#include <iostream>
#include <cstring>
using namespace std;

int count1 = 0;
int vis[10] = { 0 };    //vis储存该数是否在高位出现过，0为未出现过
int sum = 0, n;
char str[10], temp[10];
bool flag = true;   //储存是否已经搜索到了输入的数，false为搜索到，true为未搜索到

void dfs(int num)    //深搜，接收参数自左向右为第几位（当前）
{
    if (num != n)    //判断是否递归到了个位
    {
        for (int i = 1; i <= n && flag; i++)   //若还未搜索到输入数，则循环递归搜索
        {
            if (vis[i])   //若当前数被用过，则选择下一个数尝试
                continue;
            vis[i] = 1;   //先标记当前数为使用过
            temp[num - 1] = char(i + '0');    //将其放入temp字符串
            dfs(num + 1);    //探索下一位
            vis[i] = 0;      //回溯（标记为未使用过该数）
        }
    }
    else
    {
        count1++;     //个位只能是一个数了，计数器先加1
        if (strcmp(str, temp) == 0)   //比较两个字符串是否相同，若相同，则用flag标记为已经搜索到该数
            flag = false;
    }
}

int main()
{
    cin >> n;
    cin >> str;
    temp[n] = 0;
    temp[n - 1] = str[n - 1];   //将个位放入相应位置（它不需要被修改）
    
    dfs(1);
    
    cout << count1 << endl;
    return 0;
}
