#include<iostream>
using namespace std;

bool flag(int a,int b)
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
        int sum=0,fl,temp=0;
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
