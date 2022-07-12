#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int oddCells(int m, int n, vector<vector<int>> &indices) {
    auto rx = vector<int>(m, 0);
    auto cx = vector<int>(n, 0);
    for (auto &v : indices) {
      rx[v[0]]++;
      cx[v[1]]++;
    }

    int odd = 0;
    int even = 0;
    int ans = 0;
    for (auto num : rx) {
      if (num % 2 == 1) odd++;
      else even++;
    }

    ans = odd * n;

    for (auto num : cx) {
      if (num % 2 == 1) {
        ans += even;
        ans -= odd;
      }
    }

    return ans;

  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
