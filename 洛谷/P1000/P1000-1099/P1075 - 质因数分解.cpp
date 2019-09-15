//题目给出的条件，输入的数只能被分解成两个质数，所以，找到能整除的数直接输出即可
#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            cout << n / i << endl;
            return 0;
        }
    }
    return 0;
}
