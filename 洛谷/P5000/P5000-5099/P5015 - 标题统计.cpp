#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char temp;
    int count1 = 0;
    while ((temp = getchar()) && temp != '\n')
    {
        if (temp >= 'a' && temp <= 'z')
            count1++;
        else if (temp >= 'A' && temp <= 'Z')
            count1++;
        else if (temp >= '0' && temp <= '9')
            count1++;
    }
    cout << count1 << endl;
    return 0;
}
