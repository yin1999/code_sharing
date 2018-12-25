//使用深搜求解
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int sweet[10], sour[10];
int ans = 0x7fffffff;    //先赋maxint
int sour_sum = 1;
int sweet_sum = 0;
int count1 = 0;

void dfs(int num)
{
    if(num == n)
        return;
    dfs(num + 1);      //不取该材料
    
    sour_sum *= sour[num];    //取了该材料
    sweet_sum += sweet[num];
    ans = min(ans, abs(sour_sum - sweet_sum));
    dfs(num + 1);
    
    sour_sum /= sour[num];   //回溯
    sweet_sum -= sweet[num];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> sour[i] >> sweet[i];
    dfs(0);
    cout << ans << endl;
    return 0;
}
