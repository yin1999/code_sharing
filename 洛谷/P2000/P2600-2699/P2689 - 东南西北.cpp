#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2 - x1;   //dx储存两点间横坐标之差
    int dy = y2 - y1;
    int sum = abs(dx) + abs(dy);   //计算两点间的曼哈顿距离
    int n;
    cin >> n;
    char temp;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == 'W' && dx < 0)     //只有这样走减少了曼哈顿距离，才有意义，将相应的坐标差的绝对值减1
            dx++;
        else if (temp == 'E' && dx > 0)
            dx--;
        else if (temp == 'N' && dy > 0)
            dy--;
        else if (temp == 'S' && dy < 0)
            dy++;
        if (dx == 0 && dy ==0)   //当dx和dy都为0时，说明已经走到位置
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << sum << endl;
    else
        cout << -1 << endl;
    return 0;
}
