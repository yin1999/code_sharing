#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  unsigned index;
  int arr[10];
  int target;
  vector<string> ans;
  char ops[9];
  void dfs(unsigned opIndex, long long sum, long long tmp) {
    if (opIndex == index) {
      if (sum + tmp == target) {
        static char tmpStr[30];
        unsigned offset = sprintf(tmpStr, "%d", arr[0]);
        for (unsigned i = 0; i < opIndex; i++) {
          offset += sprintf(tmpStr + offset, "%c%d", ops[i], arr[i + 1]);
        }
        string t(tmpStr);
        ans.push_back(t);
      }
      return;
    }
    ops[opIndex] = '+';
    dfs(opIndex + 1, sum + tmp, arr[opIndex + 1]);

    ops[opIndex] = '-';
    dfs(opIndex + 1, sum + tmp, -arr[opIndex + 1]);

    ops[opIndex] = '*';
    dfs(opIndex + 1, sum, tmp * arr[opIndex + 1]);
  }
  inline bool continuousZeros(string s) {
    return s.length() >= 2 && s[0] == '0';
  }

 public:
  vector<string> addOperators(string num, int target) {
    this->target = target;
    unsigned baffle = 0;
    unsigned max = 1 << (num.length() - 1);
    unsigned tmp;
    string t;
    while ((tmp = baffle++) != max) {
      index = 0;
      unsigned start = 0, end = 1;
      while (tmp) {
        if (tmp & 1) {
          t = num.substr(start, end - start);
          if (continuousZeros(t)) {
            goto loop;
          }
          arr[index++] = stoi(t);
          start = end;
        }
        tmp >>= 1;
        end++;
      }
      t = num.substr(start);
      if (continuousZeros(t) || t.length() == 10 && t > "2147483647") {
        goto loop;
      }
      arr[index] = stoi(t);

      dfs(0, 0, arr[0]);
    loop:;
    }
    return ans;
  }
};
