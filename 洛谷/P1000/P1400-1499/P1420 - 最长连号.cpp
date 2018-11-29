#include<iostream>
using namespace std;

int main()
{
    int n, max = 1, max_temp = 1;    //max储存最长连号，max_temp储存当前连号长度，注意，一个数就算连号长度为1
    cin >> n;
    int *a = new int[n];   //使用new分配储存数组的空间
    if(a == NULL)
        return -1;
    cin >> a[0];
    for(int i = 1; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == a[i-1] + 1)
            max_temp++;
        else
        {
            if(max < max_temp)
                max = max_temp;
            max_temp = 1;
        }
    }
    cout << max << endl;
    return 0;
}
