#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 private:
  size_t length = 0;
  vector<int> num;
  vector<int> less_ans, greater_ans;

  bool dfs_less(size_t p, bool can_up) { // NOLINT(misc-no-recursion)
    if (p == length) {
      for (size_t i = 0; i < length; i++) {
        if (num[i] != less_ans[i]) return true;
      }
      return false;
    }

    int max_num = num[p];
    if (can_up) max_num = 9;

    for (int i = max_num; i >= 0; i--) {
      if (p == 0 && i == 0) continue;
      less_ans[p] = i;
      if (p >= length / 2) {
        if (less_ans[p] != less_ans[length - 1 - p]) continue;
      }

      bool dfs_res;
      if (i == max_num && (!can_up)) dfs_res = dfs_less(p + 1, false);
      else dfs_res = dfs_less(p + 1, true);
      if (dfs_res) return true;
    }
    return false;
  }

  bool dfs_greater(size_t p, bool can_down) { // NOLINT(misc-no-recursion)
    if (p == length) {
      for (size_t i = 0; i < length; i++) {
        if (num[i] != greater_ans[i]) return true;

      }
      return false;
    }

    int min_num = num[p];
    if (can_down) min_num = 0;

    for (int i = min_num; i <= 9; i++) {
      greater_ans[p] = i;
      if (p >= length / 2) {
        if (greater_ans[p] != greater_ans[length - 1 - p]) continue;
      }

      bool dfs_res;
      if (i == min_num && (!can_down)) dfs_res = dfs_greater(p + 1, false);
      else dfs_res = dfs_greater(p + 1, true);
      if (dfs_res) return true;
    }
    return false;
  }

  static string vector_to_string(vector<int> &v) {
    string res;
    for (int n : v) {
      res += char(n + int('0'));
    }
    if (res.length() == 0) return "0";
    return res;
  }

 public:
  string nearestPalindromic(string n) {
    length = n.length();

    if (length == 1) {
      string s(1, char(n[0] - 1));
      return s;
    }

    for (char c : n) num.push_back(int(c) - int('0'));
    less_ans.resize(length, 0);
    greater_ans.resize(length, 0);

    bool dfs_less_res = dfs_less(0, false);
    bool dfs_greater_res = dfs_greater(0, false);

    //往上找只有99…9找不到，而99…9向上10……01最近
    if (!dfs_greater_res) {
      greater_ans.resize(length + 1, 0);
      for_each(greater_ans.begin(), greater_ans.end(), [](int &n) { n = 0; });
      greater_ans[0] = greater_ans[length] = 1;
      return vector_to_string(greater_ans);
    }
    //往下找找不到，减一位变99…9，不过99…9不一定更近
    if (!dfs_less_res) {
      less_ans.resize(length - 1);
      for_each(less_ans.begin(), less_ans.end(), [](int &n) { n = 9; });
    }

    uint64_t num_n = 0, num_less = 0, num_greater = 0;

    for (int k : num) {
      num_n *= 10;
      num_n += k;
    }
    for (int k : less_ans) {
      num_less *= 10;
      num_less += k;
    }
    for (int k : greater_ans) {
      num_greater *= 10;
      num_greater += k;
    }
    if (num_n - num_less <= num_greater - num_n) {
      return vector_to_string(less_ans);
    } else {
      return vector_to_string(greater_ans);
    }
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}