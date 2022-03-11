#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 private:
  int N;
  vector<int> s;
  vector<vector<int>> child;
 public:
  int countHighestScoreNodes(vector<int> &parents) {
    N = (int) parents.size();
    s.resize(N, 0);
    child.resize(N);
    for (int i = 1; i < N; i++) {
      child[parents[i]].push_back(i);
    }

    dfs(0);

    vector<long long> res;
    long long max_res = 0;
    for (int i = 0; i < N; i++) {
      long long temp = 1;
      for (auto c : child[i]) {
        temp *= s[c];
      }
      if (i != 0) {
        temp *= s[0] - s[i];
      }
      res.push_back(temp);
      max_res = max(max_res, temp);
    }

    int ans = 0;
    for (auto n : res) {
      if (n == max_res) {
        ans++;
      }
    }
    return ans;

  }

  int dfs(int p) { // NOLINT(misc-no-recursion)
    int temp = 0;
    for (auto c : child[p]) {
      temp += dfs(c);
    }
    return s[p] = temp + 1;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
