#include <vector>

using namespace std;

class Solution {
 public:
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    for (const auto &vec: ops) {
      m = min(m, vec[0]);
      n = min(n, vec[1]);
    }
    return m * n;
  }
};
