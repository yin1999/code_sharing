#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int xor_ = 0;
    for (const int num : nums) {
      xor_ ^= num;
    }

    // int mask = xor_ & -xor_; // get the rightmost 1
    int mask = 1;
    while ((xor_ & mask) == 0) {
      mask <<= 1;
    }

    int a = 0, b = 0;
    for (const int num : nums) {
      if ((num & mask) == 0) {
        a ^= num;
      } else {
        b ^= num;
      }
    }

    return vector<int>{a, b};
  }
};
