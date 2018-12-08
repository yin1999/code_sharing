//先记录，后求解，比较简单，不解释
#include <iostream>
using namespace std;

struct point
{
    int x;
    int y;
};

int main()
{
    int n, m, count1, last_time;
    cin >> m >> n;
    point *pl = new point[m];   //左上轰炸边界
    point *pr = new point[m];   //右下轰炸边界
    for (int i = 0; i < m; i++)
        cin >> pl[i].x >> pl[i].y >> pr[i].x >> pr[i].y;
    point *key_point = new point[n];   //关键点记录
    for (int i = 0; i < n; i++)
        cin >> key_point[i].x >> key_point[i].y;
    for (int i = 0; i < n; i++)
    {
        count1 = 0;
        for (int j = 0; j < m; j++)
        {
            if (key_point[i].x >= pl[j].x && key_point[i].y >= pl[j].y && key_point[i].x <= pr[j].x && key_point[i].y <= pr[j].y)
            {
                count1++;
                last_time = j;
            }
        }
        if (count1)
            cout << "YES" << ' ' << count1 << ' ' << last_time + 1 << endl;
        else
            cout << "NO" << endl;
    }
    delete[] pl;
    delete[] pr;
    delete[] key_point;
    return 0;
}
