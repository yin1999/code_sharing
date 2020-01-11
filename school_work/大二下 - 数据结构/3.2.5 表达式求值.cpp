// 以下使用换行符代替井号，以更符合实际情况
// 针对多输空格的情况，下面对getchar进行了封装
#include <stack>
#include <iostream>
using namespace std;

inline int getch();
inline unsigned getNum(char ch);
inline char precede(char _prev, char _next);
inline bool inOperator(int ch);
inline int operate(int num1, char op, int num2);

int main() {
    stack<char> OPTR;  //运算符栈
    stack<int> OPND;   //运算数栈
    OPTR.push('\n');
    int num = 0;
    int c = getch();
    bool flag = false;
    while (c != '\n' || OPTR.top() != '\n') {
        while (!inOperator(c)) {
            flag = true;
            num = num * 10 + c - '0';
            c = getch();
        }
        if (flag) {
            OPND.push(num);
            num = 0;
            flag = false;
        }
        switch (precede(OPTR.top(), c)) {
        case '<':
            OPTR.push(c);
            c = getch();
            break;
        case '=':
            OPTR.pop();
            c = getch();
            break;
        case '>':
            char op = OPTR.top();
            OPTR.pop();
            int b = OPND.top();
            OPND.pop();
            int a = OPND.top();
            OPND.pop();
            OPND.push(operate(a, op, b));
        } // switch
    } //while
    cout << OPND.top() << endl;
} // main

inline int getch() {
    int c = getchar();
    while (c == ' ') {
        c = getchar();
    }
    return c;
}

inline unsigned getNum(char ch) {
    switch (ch) {
    case '+': return 0;
    case '-': return 1;
    case '*': return 2;
    case '/': return 3;
    case '(': return 4;
    case ')': return 5;
    case '\n': return 6;
    } // switch
    exit(-1);  //error
} // getNum

inline char precede(char _prev, char _next) {
    static char map[7][7] = {
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'<', '<', '<', '<', '<', '=',  0 },
        {'>', '>', '>', '>',  0 , '>', '>'},
        {'<', '<', '<', '<', '<',  0 , '='}
    };
    return map[getNum(_prev)][getNum(_next)];
} // precede

inline bool inOperator(int ch) {
    return !(ch >= '0' && ch <= '9'); 
} // inOperator

inline int operate(int num1, char op, int num2) {
    if (op == '+') {
        return num1 + num2;
    }
    if (op == '-') {
        return num1 - num2;
    }
    if (op == '*') {
        return num1 * num2;
    }
    if (op == '/') {
        return num1 / num2;
    }
    exit(-1);  //error!
} // operator
