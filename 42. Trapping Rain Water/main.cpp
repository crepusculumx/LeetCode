#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 private:
  vector<int> l, r;
  size_t length;
 public:
  int trap(vector<int> &height) {
    length = height.size();
    l.resize(height.size(), 0);
    r.resize(height.size(), 0);

    l[0] = height[0];
    r.back() = height.back();

    for (size_t i = 1; i < height.size(); i++) {
      l[i] = max(height[i], l[i - 1]);
    }

    for (int i = static_cast<int>(height.size()) - 2; i >= 0; i--) {
      r[i] = max(height[i], r[i + 1]);
    }

    int res = 0;
    for (size_t i = 1; i < height.size() - 1; i++) {
      if (l[i - 1] <= height[i] || r[i + 1] <= height[i]) continue;
      res += min(l[i - 1], r[i + 1]) - height[i];
    }
    return res;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
