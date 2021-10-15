#include <string>
#include <cstdio>

using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    char ans[2][5000] = {{'1'}, {'1'}};
    char in, out;
    while (--n) {
      in = n & 1;
      out = !in;
      char before = 0;
      int count = 0;
      unsigned offset = 0;
      for (unsigned i = 0; ans[in][i] != 0; ++i) {
        if (ans[in][i] == before) {
          ++count;
        } else {
          if (count) {
            offset += sprintf(ans[out] + offset, "%d%c", count, before);
          }
          before = ans[in][i];
          count = 1;
        }
      }
      sprintf(ans[out]+offset, "%d%c", count, before);
    }
    return string(ans[out]);
  }
};
