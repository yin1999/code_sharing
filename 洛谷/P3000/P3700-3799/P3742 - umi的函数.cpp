#include<iostream>
using namespace std;

int main()
{
    int n;
    char x[101], y[101], z[101];
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++)
    {
        if(x[i] < y[i])    //只有一种情况是不存在的，结果中的字母比输入进去的字母大，其它爱怎么水怎么水
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            if(x[i] == y[i] && x[i] != 'z')  //为了不水经验，特加上此判断，若只是想水，可以删掉此if语句，直接使用z[i] = y[i];
                z[i] = x[i] + 1;
            else
                z[i] = y[i];
        }
    }
    z[n] = '\0';  //结束控制符不能丢！！
    cout << z << endl;
    return 0;
}
