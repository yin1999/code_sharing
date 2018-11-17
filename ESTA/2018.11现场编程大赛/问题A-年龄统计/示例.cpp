//使用桶排序，将相应年龄的人数统计到相应的数组中，再按要求输出
#include<iostream>
using namespace std;

void printyear(int year,int num)
{
    while(num--)
        cout<<year<<" ";
}

int main()
{
    int a[101]={0};   //分别记录0-100岁的人数，初始化为0
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        a[temp]++;
    }
    for(int y=0;y<=100;y++)
    {
        if(a[y]!=0)    //如果人数不为0，输出相应个数
            printyear(y,a[y]);
    }
    return 0;
}
