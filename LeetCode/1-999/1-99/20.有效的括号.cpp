 #include <string>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    char p[7000] = {};    // 使用数组来模拟栈结构
    unsigned index = -1;
    for (const char ch : s) {
      switch (ch) {
        case '(':
        case '[':
        case '{':
          p[++index] = ch;
          break;
        case ')':
          if (index == -1 || p[index--] != '(') {
            return false;
          }
          break;
        case ']':
          if (index == -1 || p[index--] != '[') {
            return false;
          }
          break;
        case '}':
          if (index == -1 || p[index--] != '{') {
            return false;
          }
          break;
      }
    }
    return index == -1;
  }
};
