// 使用vs的用户请加上以下语句（从vs的错误中复制也行）：#define _CRT_SECURE_NO_WARNINGS
// C++版本
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    char fileName[100];
    int a;
    while (cin >> a) {
        //文件输出流，将数据保存到"输入的文件名".txt中
        sprintf(fileName, "%d.txt", a);
        ofstream file(fileName);
        int n = rand() % 1000;           //rand%1000 表示生成一个0-999的数字，可以修改百分号后的数字以修改数据的范围
        //file << n << endl;             //如果需要输入样例数量，请取消本行注释
        for (int i = 0; i < n; i++) {
            file << rand() % 1000001 << ' ';   //生成每行的数据
            file << rand() % 1000001 << endl;
        }
        file.close();
    }
    return 0;
}
