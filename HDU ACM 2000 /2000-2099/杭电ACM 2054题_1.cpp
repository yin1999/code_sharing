//此方法较为复杂，直接判断两个数是否相等
#include<iostream>
#include<string>
using namespace std;

bool ifzero(string temp,int i)   //判断字符串从i位起是否都为0
{
    int length=temp.size();
    for(;i<length;i++)
        if(temp[i]!='0')
            return false;
    return true;
}

bool equal_judge(string a,string b)   //判断是否相等
{
    int length_a=a.size();
    int length_b=b.size();
    int i=0,point_a=0,point_b=0;
    for(;i<length_a&&i<length_b;i++)
    {
        if((!point_a)&&a[i]=='.')
            point_a=i;
        if((!point_b)&&b[i]=='.')
            point_b=i;
        if(a[i]!=b[i])
            break;
    }
    if(i==length_a&&i==length_b)
        return true;
    if(a[i]=='.'&&i==length_b)   //当遇到a的当前位是小数点且b刚好结束时
    {
        if(ifzero(a,i+1))
            return true;
        else
            return false;
    }
    else if(b[i]=='.'&&i==length_a)  //当遇到b的当前位是小数点且a刚好结束时
    {
        if(ifzero(b,i+1))
            return true;
        else
            return false;
    }
    else if(i>point_a&&i>point_b&&a[i-1]==b[i-1])   //当遇到有一个字符串已经结束时
    {
        if(point_a&&point_b&&ifzero(a,i)&&ifzero(b,i))   //判断是否都存在小数点且较长者后几位全是0
            return true;
        else
            return false;
    }
    else
        return false;   //其它情况一概false
}


int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        if(equal_judge(a,b))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
