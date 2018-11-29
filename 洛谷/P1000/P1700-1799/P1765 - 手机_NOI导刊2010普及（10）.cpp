#include<iostream>
using namespace std;

int main()
{
    char str[220];
    int a[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3 ,4};
    cin.getline(str, 1024);
    int i = -1;
    int sum = 0;
    while(str[++i])
    {
        if(str[i] == ' ')
          sum++;
        if(str[i] >= 'a' && str[i] <= 'z')   //不能写成else，坑爹的题目测试的样例里面有'\r'
          sum += a[str[i] - 'a'];
    }
    cout << sum << endl;
    return 0;
}
