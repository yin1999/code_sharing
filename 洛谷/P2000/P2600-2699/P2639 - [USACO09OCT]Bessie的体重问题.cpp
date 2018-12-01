//动规问题
#include<iostream>
using namespace std;

bool flag[45001] = {true};    //flag[0] = true !
int n, h, w;

int main()
{
    cin >> h >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> w;
        for(int v = h; v >= w; v--)
            flag[v] = flag[v] || flag[v - w];
    }
    for(int i = h; i >= 0; i--)
    {
        if(flag[i])
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
