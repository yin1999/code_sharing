// 最多获得的糖果数为`总糖果数量一半`和`所有糖果的总类`中的较小值
#include <vector>

using namespace std;

class Solution {
 public:
  int distributeCandies(vector<int>& candyType) {
    bool kinds[200005] = {};
    for (const int candy : candyType) {
      kinds[candy+100000] = true;
    }
    unsigned sum = 0;
    for (unsigned i = 200004; i--;) {
      sum += kinds[i];
    }
    return min(sum, unsigned(candyType.size())>>1);
  }
};
