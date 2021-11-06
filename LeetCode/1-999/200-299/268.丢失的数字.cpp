#include <vector>

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = nums.size(); i;) {
      ans ^= i--;
      ans ^= nums[i];
    }
    return ans;
  }
};
