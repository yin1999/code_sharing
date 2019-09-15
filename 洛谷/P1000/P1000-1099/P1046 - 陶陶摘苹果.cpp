#include<iostream>
using namespace std;

int main() {
    int a[10], n;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    cin >> n;
    int max_level = n + 30;    //最大高度
    int count1 = 0;   //计数
    for (int i = 0; i < 10; i++) {
        if(max_level >= a[i]) {
            count1++;
        }
    }
    cout << count1 << endl;
    return 0;
}
