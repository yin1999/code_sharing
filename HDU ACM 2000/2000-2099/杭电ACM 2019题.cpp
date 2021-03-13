//这题我用自己写的代码死活不给过，本地测试正常，如下AC代码为其他码农所写
#include <stdio.h>
 
int main(void)
{
    int n, m, val, i;
 
    while(scanf("%d%d", &n, &m) != EOF) {
        if(n == 0 && m == 0)
            break;
 
        if(n == 0) {
            printf("%d\n", m);
        } else {
            int flag = 1;
            for(i=0; i<n; i++) {
                scanf("%d", &val);
 
                if(flag && val >= m) {
                    if(i == 0)
                        printf("%d", m);
                    else
                        printf(" %d", m);
                    flag = 0;
                }
 
                if(i>0 || !flag)
                    printf(" ");
                printf("%d", val);
            }
            if(flag)
                printf(" %d", m);
            printf("\n");
        }
    }
 
    return 0;
}
