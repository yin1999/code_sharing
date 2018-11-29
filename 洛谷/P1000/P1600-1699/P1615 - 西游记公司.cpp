#include<iostream>
using namespace std;

int main()
{
    int s_h, s_m, s_s, e_h, e_m, e_s;
    char temp;
    int speed;
    cin >> s_h >> temp >> s_m >> temp >> s_s >> e_h >> temp >> e_m >> temp >> e_s;
    cin >> speed;
    long long sum_s = (e_h - s_h) * 3600 + (e_m - s_m) * 60 + e_s - s_s;   //计算总时间
    cout << speed * sum_s;
    return 0;
}
