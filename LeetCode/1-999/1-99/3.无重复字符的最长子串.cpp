#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unsigned chars[128] = {};
    unsigned length = s.length();
    unsigned start = 0;
    unsigned maxLength = 0;
    for (unsigned i = 0 ; i < length; i++) {
      start = max(start, chars[s[i]]);
      maxLength = max(maxLength, i+1-start);
      chars[s[i]] = i+1;
    }
    return maxLength;
  }
};
