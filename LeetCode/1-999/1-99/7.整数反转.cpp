class Solution {
 public:
  int reverse(int x) {
    long n = 0;
    while (x) {
      n = n * 10 + x % 10;
      x /= 10;
    }
    return n > __INT_MAX__ || n < (-__INT_MAX__ - 1) ? 0 : n;
  }
};
