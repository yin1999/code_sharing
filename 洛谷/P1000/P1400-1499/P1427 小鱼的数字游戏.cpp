#include<iostream>
using namespace std;

int main()
{
    int a[128];
    int i = -1;
    do{
        cin >> a[++i];

    }while(a[i]);   //当a[i] == 0时，终止do-while循环
    for(i--; i > 0; i--)
        cout << a[i] << " ";
    cout << a[0] << endl;
    return 0;
}
