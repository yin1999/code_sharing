#include<iostream>
using namespace std;

int main()
{
    int a[42] = {0};   //定义数组初始化为0，用于储存是否有取余后相应的结果，有则记录1
    int n;
    for(int i = 0; i < 10; i++)
    {
        cin >> n;
        a[n % 42] = 1;
    }
    int sum = 0;
    for(int i = 0; i < 42; i++)   //加起来直接输出结果
        sum += a[i];
    cout << sum << endl;
    return 0;
}
