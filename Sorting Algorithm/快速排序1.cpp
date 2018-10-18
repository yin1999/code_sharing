//快速排序算法 数组限制为10000个，且为整型
#include<iostream>
using namespace std;

int main()
{
int num[10001]={0};
int N, i = 1;
while(1)
{
while(cin>>N)
{
num[N]+=1;
i++;
}
for(int j=0,k=1;k<=i;)
{
if(num[j]!=0)
{
cout<<num[j]<<" ";
num[j]-=1;
k++;
}
else
j++;
}
}
}
