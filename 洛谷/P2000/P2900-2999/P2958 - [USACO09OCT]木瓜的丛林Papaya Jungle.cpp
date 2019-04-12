//每次奶牛走到一个格子都在它四周的四个方向上找值最大的一个点，然后移动到那个点，如此往复，直到走到(R,C)点终止
#include <iostream>
using namespace std;

int maze[40][40] = { 0 };
int R, C;

struct xy
{
    int x, y;
};

xy FindMaxNum(int x, int y)
{
    int _x = x, _y = y;
    int x1 = max(x - 1, 0);
    int x2 = min(x + 1, R);
    int y1 = max(y - 1, 0);
    int y2 = min(y + 1, C);
    if (maze[x1][y] > maze[_x][_y])
        _x = x1, _y = y;
    if (maze[x2][y] > maze[_x][_y])
        _x = x2, _y = y;
    if (maze[x][y1] > maze[_x][_y])
        _x = x, _y = y1;
    if (maze[x][y2] > maze[_x][_y])
        _x = x, _y = y2;
    return { _x, _y };
}

int main()
{
    cin >> R >> C;
    R--;
    C--;
    for (int i = 0; i <= R; i++)
    {
        for (int j = 0; j <= C; j++)
            cin >> maze[i][j];
    }
    int sum = maze[0][0];
    maze[0][0] = 0;
    xy temp = { 0, 0 };
    while (temp.x != R || temp.y != C)
    {
        temp = FindMaxNum(temp.x, temp.y);
        sum += maze[temp.x][temp.y];
        maze[temp.x][temp.y] = 0;
    }
    cout << sum << endl;
    return 0;
}
