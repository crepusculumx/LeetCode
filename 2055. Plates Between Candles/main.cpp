#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int len;
 public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
    len = (int) s.length();
    vector<int> sum(len, 0);
    vector<int> l(len, 0), r(len, 0);

    (s[0] == '*')?sum[0] = 1:sum[0] = 0;
    for (int i = 1; i < len; i++) {
      if (s[i] == '*') sum[i] = sum[i - 1] + 1;
      else sum[i] = sum[i - 1];
    }

    int last_l = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] != '*') last_l = i;
      l[i] = last_l;
    }

    int last_r = len;
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] != '*') last_r = i;
      r[i] = last_r;
    }

    vector<int> res;
    for (auto &v : queries) {
      int lp = v[0];
      int rp = v[1];

      int t = (lp == 0) ? sum[rp] : sum[rp] - sum[lp - 1];
      res.emplace_back(t - (r[lp] - lp + 1) - (rp - l[rp] + 1));
    }

    return res;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
