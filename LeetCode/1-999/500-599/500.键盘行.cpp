#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  inline unsigned toIndex(char ch) { return ch >= 'a' ? ch - 'a' : ch - 'A'; }

 public:
  vector<string> findWords(vector<string>& words) {
    unsigned index[] = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2,
                        2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
    vector<string> ans;
    for (const string word : words) {
      const unsigned first = index[toIndex(word[0])];
      int i = word.length();
      while (i-- && first == index[toIndex(word[i])]) {
      }
      if (i == -1) {
        ans.push_back(word);
      }
    }
    return ans;
  }
};
