#include<iostream>
using namespace std;

int main()
{
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int a[81] = {0};
    for(int i = 1; i <= s1; i++)
    {
        for(int j = 1; j <= s2; j++)
        {
            for(int k = 1; k <= s3; k++)
                a[i + j + k]++;
        }
    }
    int max = 1;   //储存最大数，开始取1（可以从3开始）
    for(int i = 2; i <= 50; i++)   //50即可，取到81就是浪费，后面的肯定没前面的大（50也只是适当数，不是很精确的）
    {
        if(a[max] < a[i])
            max = i;
    }
    cout << max << endl;
    return 0;
}
