// 思路：因为需要得到数字n在任意排列（除去有前导零的情况）下，能否组成结果为2的幂的数
// 而能否组成的关键只在于，当前数中0-9中，每一个数字出现的次数是否能和某一个2的幂中的一一对应
// 所以，我们只需要先统计出每一个数字出现的次数，然后再枚举2的幂进行比对即可
// 题解中采用了状态压缩的方法来得到代表每种数字出现次数的状态量(check_sum)
// 具体做法为：将无符号64位整型从低到高每4位(0~15，同一种数字最多出现9次)表示一种数字的出现次数
#include <string>

using namespace std;

class Solution {
 public:
  bool reorderedPowerOf2(int n) {
    string s = to_string(n);
    unsigned long long n_check_sum = 0;
    for (const char ch : s) {
      n_check_sum += 1ULL << ((ch - '0') << 2); // 乘4
    }

    for (unsigned i = 1; i <= 1e9; i <<= 1) {
      string str = to_string(i);
      unsigned long long check_sum = 0;
      for (const char ch : str) {
        check_sum += 1ULL << ((ch - '0') << 2);
      }

      if (n_check_sum == check_sum) {
        return true;
      }
    }

    return false;
  }
};
