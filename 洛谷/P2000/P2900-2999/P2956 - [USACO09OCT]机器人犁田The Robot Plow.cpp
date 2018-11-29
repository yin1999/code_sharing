//创建二维数组创建一个地图，地图内的每一个点表示一单位的面积
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int maze[245][245] = {0};   //初始化为0，表示未被犁过
    int x, y, l;
    int x1, y1, x2, y2;
    cin >> x >> y >> l;
    while(l--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        x2 = min(x2, x);
        y2 = min(y2, y);
        for(int i = x1; i <= x2; i++)
        {
            for(int j = y1; j <= y2; j++)
                maze[i][j] = 1;
        }
    }
    
    int sum1 = 0;   //计算一共犁了多少地
    for(int i = 0; i <= x; i++)
    {
        for(int j = 0; j <=  y; j++)
            sum1 += maze[i][j];
    }
    cout << sum1 << endl;
    return 0;
}
