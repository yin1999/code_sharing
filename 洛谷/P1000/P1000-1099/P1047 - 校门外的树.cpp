#include <iostream>
using namespace std;

int main() {
    int L, M, i;
    cin >> L >> M;
    
    int *a = new int[L + 1];   //开辟数组，初始化为1
    for (i = 0; i <= L; i++)
        a[i] = 1;
        
    int left, right;
    while (M--) {
        cin >> left >> right;
        for (i = left; i <= right; i++) {
            a[i] = 0;
        }
    }
    
    int sum = 0;
    for (i = 0; i <= L; i++) {  //求和，为1的就是那棵树还在
        sum += a[i];
    }
        
    delete[] a;
    
    cout << sum << endl;
    return 0;
}
