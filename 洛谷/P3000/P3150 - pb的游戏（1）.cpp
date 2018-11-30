//如何保证对方赢不了，每次割出一个1，对方不可能选1
//但不得不说，这题太水了，一开始是几就决定了谁能赢
#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    while(n--)
    {
        cin >> m;
        if(m & 1)    //效果同m % 2
            cout << "zs wins" << endl;
        else
            cout << "pb wins" << endl;
    }
    return 0;
}
