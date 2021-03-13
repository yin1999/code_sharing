//此方法是，先判断一个数是否有小数部分，如果有，则去掉其中的小数点与末位可能出现的0（用空字符代替），再比较两个字符串是否相同
#include<iostream>
#include<cstring>
char a[100000],b[100000];
void change(char s[])
{
    int len,i;
    len=strlen(s);
    if(strstr(s,"."))
    {
        for(i=len-1;s[i]=='0';i--)
        {
            s[i]='\0';
            len--;
        }
    }
    if(s[len-1]=='.')
        s[len-1]='\0';
}

int main()
{
    while(cin >> a >> b)
    {
        change(a);
        change(b);
        if(strcmp(a,b)==0)
            cout<< "YES" << endl;
        else
            cout<< "NO" << endl;
    }
    return 0;
}
