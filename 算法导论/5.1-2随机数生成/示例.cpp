#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

unsigned int rand_0_to_1() {  //随机生成0或1
    return (rand() & 1);
}

int RAND(unsigned int a, unsigned int b) {  //a到b范围数随机生成
    unsigned int n = b - a;
    unsigned int bits = 0;
    unsigned int temp = n;
    while (temp) {
        temp >>= 1;
        bits++;
    }
    unsigned int result = n + 1;
    while (result > n) {
        result = 0;
        for (int i = 0; i < bits; i++) {
            result <<= 1;
            result += rand_0_to_1();
        }
    }
    return result + a;
}

int main() {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 100; i++) {
        cout << RAND(0, 100) << '\t';   //随机生成0到100的无符号整数（可修改范围）
    }
    cout << endl;
    return 0;
}
