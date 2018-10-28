//看以下代码以前，建议先去看一下EOF，知道了的请忽略这句话，我还是一个小萌新
//现学现卖
#include<iostream>
#include<cstdio>
using namespace std;

void swap(char &a)
{
    if(a>='a'&&a<='z')
        a-=32;
}

int main()
{
    char str[100];
    while((str[0]=getchar())!=EOF)   //不懂EOF还真不行，ｏｊ还是需要判断是否返回０的
    {
        int length =1;
        for(int i=1;i<100;i++)
        {
            str[i]=getchar();
            if(str[i]=='\n')
            {
                str[i]='\0';  //这一步一定要有，不然乱码等着你，字符串以'\o'来判断是否结束
                break;
            }
            length++;
        }
        swap(str[0]);
        for(int j=1;j<length;j++)
        {
            if(str[j-1]==' ')
                swap(str[j]);
        }
        cout<<str<<endl;
    }
}
