#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 private:
  vector<int> res;
  bool dfs(int n, int sum, int k) {
    if (n == 0 && sum == 0) return true;
    if (sum < n) return false;
    if (sum > n * k) return false;

    for (int i = 6; i >= 1; i--) {
      res.push_back(i);
      bool dfs_res = dfs(n - 1, sum - i, k);
      if (dfs_res) return true;
      res.pop_back();
    }
    return false;
  }
 public:
  vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
    int m = static_cast<int>(rolls.size());
    int sum = mean * (m + n);
    for_each(rolls.begin(), rolls.end(), [&sum](int x) { sum -= x; });
    dfs(n, sum, 6);
    return res;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
