#include<iostream>
using namespace std;

bool flag(int a,int b)   //判断是否为上升，上升返回true，下降返回false
{
    if(a>b)
        return true;
    else
        return false;
}
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        int sum=0,fl,temp=0;  //temp储存上一个楼层，初始状态为0，底层
        for(int i=0;i<n;i++)
        {
            cin >>fl;
            if(flag(fl,temp))
                sum=sum+(fl-temp)*6+5;
            else
                sum=sum+(temp-fl)*4+5;
            temp=fl;
        }
        cout<<sum<<endl;
    }
    return 0;
}
