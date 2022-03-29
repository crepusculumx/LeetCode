#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int cnt(string &answerKey, int k, char ch) {
    int n = static_cast<int>(answerKey.length());
    int ans = 0;
    int l = 0, r = 0, sum = 0;
    for (; r < n; r++) {
      sum += answerKey[r] != ch;
      while (sum > k) {
        sum -= answerKey[l++] != ch;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }

  int maxConsecutiveAnswers(string answerKey, int k) {
    return max(cnt(answerKey, k, 'T'), cnt(answerKey, k, 'F'));
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
