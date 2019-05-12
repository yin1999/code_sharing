#include <cstdio>
using namespace std;


int main()
{
    unsigned n, L, G;
    scanf("%u%u%u", &n, &L, &G);
    unsigned* array = new unsigned[n];
    unsigned W, H, i;
    for (i = 0; i < n; i++)
    {
        scanf("%u%u", &W, & H);
        
        while (W > G || H > G)   //如果边长过大，各自整除2
        {
            W >>= 1;
            H >>= 1;
        }
        
        if (W < L || H < L)   //长度小于L，不符合条件
            array[i] = 0;
        else if (W != H)     //边长不相等
            array[i] = 1;
        else
            array[i] = 2;    //边长相等
    }
    
    for (i = 0; i < n; i++)   //输出
    {
        if (array[i] == 0)
            printf("Too Young\n");
        else if (array[i] == 1)
            printf("Too Simple\n");
        else
            printf("Sometimes Naive\n");
    }
    return 0;
}
