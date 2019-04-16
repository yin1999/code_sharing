#include <iostream>
using namespace std;

int main()
{
    int n;
    string str;
    cin >> str >> n;
    int x = 0, y = 0, tx, ty;
    for (int i = 0;; i++, n--)
    {
        if (str[i] == 'N')
            y++;
        else if (str[i] == 'E')
            x++;
        else if (str[i] == 'W')
            x--;
        else
            y--;
        if (n == 1)
        {
            break;
        }
        if (i == str.size() - 1)   //储存遍历一遍字符串后x与y的变化量
        {
            i = -1;
            tx = x;
            ty = y;
            while (n > str.size())    //当n大于字符串长度时，减去字符串长度，同时使x与y的值分别增加tx，ty
            {
                n -= str.size();
                x += tx;
                y += ty;
            }
        }
    }
    cout << x << ' ' << y << endl;
    return 0;
}
