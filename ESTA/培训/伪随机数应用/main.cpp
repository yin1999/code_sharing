#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include <iostream>
using namespace std;

class LFSR {
private:
    unsigned n;
    unsigned num;
    unsigned carryOut;
public:
    unsigned operator()() {
        num <<= 1;
        carryOut = num >> n;
        num = (num & ((1 << n) - 1)) + carryOut;
        num = num ^ (carryOut << 1);
        return num;
    }
    void init(unsigned seed = 1, unsigned n = 4) {
        this->n = n;
        this->num = seed;
    }
    LFSR(unsigned seed = 1, unsigned n = 4) {
        this->n = n;
        this->num = seed;
    }
};

int main() {
    srand(time(NULL));
    uint8_t key[5*1024];    //定义一个1个区块数量为5，密钥长度为1024
    int k = 3;
    for (int i = 0; i < 1024; i++) {  //密钥生成
        key[k*1024+i] = rand() & 1;
    }
    unsigned seed = rand() & ((1 << 10) - 1);
    while (seed == 0) {
        seed = rand() & ((1 << 10) - 1);
    }
    LFSR l(seed, 10);
    char message[129] = {};
    for (int i = 0; i < 128; i++) {
        message[i] = key[k*1024 - 1 + l()] + '0';
    }
    cout << "密钥传递: " << message << endl;
    l.init(seed, 10);
    bool flag = true;
    for (int i = 0; i < 128; i++) {
        if (message[i] != key[k*1024 - 1 + l()] + '0') {
            cout << "设备认证失败\n";
            flag = false;
            break;
        }
    }
    if (flag == true) {  // 验证成功
        // server端
        int serverNewK = 4;
        int msgK = serverNewK ^ k;
        // device端
        int deviceNewK = msgK ^ k;  //得到服务器端指定的新k
        uint8_t newPasswd[129] = {};
        for (int i = 0; i < 1024; i++) {  //密钥生成
            key[deviceNewK*1024+i] = rand() & 1;
            newPasswd[i] = key[k*1024 + i] ^ key[deviceNewK*1024 + i];
        }
        // server端
        for (int i = 0; i < 1024; i++) {  //密钥解析
            if (key[serverNewK*1024 + i] != (newPasswd[i] ^ key[k*1024 + i])) {
                cout << "密码恢复失败\n";
                break;
            }
        }
        // 打印原始密钥、中间传输数据以及新密钥的前40位
        cout << "原始: ";
        for (int i = 0; i < 40; i++) {
            printf("%d", key[k*1024 + i]);
        }
        cout << endl << "中间: ";
        for (int i = 0; i < 40; i++) {
            printf("%d", newPasswd[i]);
        }
        cout << endl << "更新: ";
        for (int i = 0; i < 40; i++) {
            printf("%d", key[serverNewK*1024 + i]);
        }
        cout << endl;
    }
    return 0;
}

// int main() {
//     LFSR l(8, 4);
//     for (int i = 0; i < 20; i++) {
//         cout << l() << '\t';
//     }
//     cout << endl;
//     return 0;
// }
