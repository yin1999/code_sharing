#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> strs;
    for (const int i : nums) {
      strs.push_back(to_string(i));
    }

    sort(strs.begin(), strs.end(),
         [](const string& a, const string& b) { return a + b > b + a; });

    string res;
    for (const string& s : strs) {
      res += s;
    }

    if (res[0] == '0') {
      return "0";
    }

    return res;
  }
};
