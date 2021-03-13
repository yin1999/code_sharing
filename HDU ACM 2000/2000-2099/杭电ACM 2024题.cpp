//对于这一题，我什么都不想讲了，wrong answer在等着你，让其它人也看了，看不出错误，以下的代码转自他人
#include<stdio.h>
int main()
{
    char a[55];
    int n,i,flag1,flag2;
    scanf("%d",&n);
    getchar();
    while(n>0)
    {

        flag1=0;
        flag2=0;
        gets(a);
        for(i=0;a[i]!='\0';i++)
        {
            if(((a[0]>='A'&&a[0]<='Z')||(a[0]>='a'&&a[0]<='z')||a[0]=='_'))
            {
                flag1=0;
            }
            else
            {
                flag1=1;
                break;
            }
            if(i!=0)
            {
                if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')||a[i]=='_'||(a[i]>='0'&&a[i]<='9'))
                {
                    flag2=0;
                }
                else
                {
                    flag2=1;
                    break;
                }
            }
        }
        if(flag1==1||flag2==1)
            printf("no\n");
        else
            printf("yes\n");
        n--;
    }
    return 0;
}
