//动规问题，01背包
#include<iostream>
using namespace std;

bool flag[50001] = {true};

int main()
{
    int c, h, t;
    cin >> c >> h;
    for(int i = 0; i < h; i++)
    {
        cin >> t;
        for(int j = c; j >= t; j--)
            flag[j] = flag[j] || flag[j - t];
    }
    for(int i = c; i >= 0; i--)
    {
        if(flag[i])
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
