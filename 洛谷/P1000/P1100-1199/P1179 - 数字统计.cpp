从大到小找，找出每一个数中的2，比较水，就不详解了
#include<iostream>
using namespace std;

int main()
{
    int L, H, count1 = 0, temp;
    cin >> L >> H;
    while(L <= H)
    {
        temp = H;
        while(temp)
        {
            if(temp % 10 == 2)
                count1++;
            temp /= 10;
        }
        H--;
    }
    cout << count1 << endl;
}
