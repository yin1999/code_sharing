//思路，一个数字n无论在哪一位，它与9取余等于n与9取余，因为10%9 = 1. n*10%9 = n*(10%9) = n%9
//所以只要判断是否有0（能被90中的10整除），有0则一定有结果，若5的个数少于9，则输出0，若大于9，则取5的个数减去5的个数与9取余的结果个5（可能有些绕口
//简写就是取的5的个数是(5的总个数five) five - five % 9
#include<iostream>
using namespace std;

int main()
{
    int n, five = 0, zero = 0, temp;
    cin >> n;
    while(n--)
    {
        cin >> temp;
        if(temp == 5)
            five++;
        else
            zero++;
    }
    if(zero == 0)
        cout << "-1" << endl;
    else
    {
        if(five < 9)
            cout << '0' << endl;
        else
        {
            int z = five - five % 9;
            for(int i = 0; i < z; i++)
                cout << '5';
            for(int i = 0; i < zero; i++)
                cout << '0';
            cout << endl;
        }
    }
    return 0;
}
