#include<iostream>
#include<string>
#include<cstdio>
using namespace std;


int main()
{
    int filename_length,count_temp=0,count_sum=0;
    string file_name;
    cin>>filename_length;
    getchar();   //接收上一行输入文件名的长度产生的换行符
    getline(cin,file_name);
    for(int i=0;i<filename_length;i++)
    {
        if(file_name[i]<0)    //若文件名带有中文，则step 2(中文占两个字节，其二进制位转换成int型小于0
        {
            i++;
            continue;
        }
        
        if(file_name[i]=='x')
            count_temp++;
        else if(count_temp>2)
        {
            count_sum+=count_temp-2;
            count_temp=0;
        }
        else
            count_temp=0;
    }
    if(count_temp>2)    //考虑连续的x可能出现在结尾
        count_sum+=count_temp-2;
    cout<<count_sum<<endl;
    return 0;
}
