#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, unsigned> num_map;
    for (unsigned i = nums.size(); i--;) {
      num_map[target - nums[i]] = i;
    }
    for (unsigned i = nums.size(); i--;) {
      if (num_map.find(nums[i]) != num_map.end() && num_map[nums[i]] != i) {
        return vector<int>{int(i), int(num_map[nums[i]])};
      }
    }

    return vector<int>{};
  }
};
