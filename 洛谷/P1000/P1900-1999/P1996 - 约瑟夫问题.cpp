//定义一个长度为101的数组，分别储存0-100，然后，按步数一步一步模拟，如果走到某一个数了，把它从数组中移除，
//并把后面的数组向前移动，数组最后一个数的下标自减，然后继续一步一步模拟，如果走到最后一个数了，就将模拟下标改成1继续模拟
#include <iostream>
using namespace std;

int main()
{
    int n, m, i;
    cin >> n >> m;
    int t = n, end = n;
    int vis[101];
    for (i = 1; i <= n; i++)
        vis[i] = i;
    int step = 0;
    while (t--)
    {
    //********步数模拟
        for (i = 0; i < m;)
        {
            step++;
            i++;
            if (step > end)
                step = 1;
        }
   //*********步数模拟结束 
        cout << vis[step] << ' ';
        for (i = step; i < end; i++)
        {
            vis[i] = vis[i + 1];
        }
        step--;     //注意，把数组整体向前移动一以后，相当于走了一步，得把这一步撤销掉，在之前的步数模拟中加一步会在最后两个数的顺序上出现问题！！！
        end--;
        if (step == 0)   //同上，step==0时，相当于走到最后一个数
            step = end;
    }
    return 0;
}
