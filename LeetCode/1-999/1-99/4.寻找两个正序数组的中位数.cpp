#include <vector>

using namespace std;

class Solution {
 private:
  double get_middle_nums(vector<int>& nums1, vector<int>& nums2, unsigned i,
                         unsigned j) {
    if (i + 1 != nums1.size() &&
        (j + 1 == nums2.size() || nums1[i + 1] <= nums2[j + 1])) {
      return (nums1[i] + nums1[i + 1]) / 2.;
    }
    return (nums1[i] + nums2[j + 1]) / 2.;
  }

 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    unsigned nums1_length = nums1.size(), nums2_length = nums2.size();
    unsigned length = nums1_length + nums2_length;
    unsigned mid_index = (length - 1) >> 1;
    unsigned i = 0, j = 0;
    unsigned index = -1;
    unsigned sel = nums1_length <= nums2_length;

    for (; i != nums1_length && j != nums2_length && index != mid_index;
         index++) {
      if (nums1[i] <= nums2[j]) {
        i++;
        sel = 0;
      } else {
        j++;
        sel = 1;
      }
    }

    if (index != mid_index) {
      if (i != nums1_length) {
        i += mid_index - index;
        sel = 0;
      } else {
        j += mid_index - index;
        sel = 1;
      }
      index = mid_index;
    }
    i--;
    j--;
    if (length & 1) {  // odd
      if (sel == 0) {
        return nums1[i];
      } else {
        return nums2[j];
      }
    } else if (i != nums1_length && j != nums2_length) {
      if (sel == 0) {
        return get_middle_nums(nums1, nums2, i, j);
      }
      return get_middle_nums(nums2, nums1, j, i);
    } else {
      if (i != nums1_length) {
        return (nums1[i] + nums1[i + 1]) / 2.;
      }
      return (nums2[j] + nums2[j + 1]) / 2.;
    }
  }
};
