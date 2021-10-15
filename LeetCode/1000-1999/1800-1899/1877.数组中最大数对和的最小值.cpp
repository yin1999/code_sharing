#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int max = -0xff;
    for (int i = 0, right = nums.size() - 1; i < right; ++i, --right) {
      int tmp = nums[i] + nums[right];
      if (tmp > max) {
        max = tmp;
      }
    }
    return max;
  }
};
