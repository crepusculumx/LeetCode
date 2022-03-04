#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  size_t length;
  vector<int> dp_l, dp_r;

 public:
  int largestRectangleArea(vector<int> &heights) {
    length = heights.size();
    dp_l.resize(length, 0);
    dp_r.resize(length, 0);

    dp_r[0] = heights[0];
    dp_l.back() = heights.back();
    for (size_t i = 1; i < length; i++) {
      if (heights[i - 1] < heights[i]) {
        dp_r[i] = heights[i];
      } else if (heights[i - 1] == heights[i]) {
        dp_r[i] = heights[i] + dp_r[i - 1];
      } else {
        dp_r[i] = heights[i] + dp_r[i - 1] / heights[i - 1] * heights[i];
      }
    }

    for (int i = static_cast<int>(length) - 2; i >= 0; i--) {
      if (heights[i + 1] < heights[i]) {
        dp_l[i] = heights[i];
      } else if (heights[i + 1] == heights[i]) {
        dp_l[i] = heights[i] + dp_l[i + 1];
      } else {
        dp_l[i] = heights[i] + dp_l[i + 1] / heights[i + 1] * heights[i];
      }
    }

    int res = 0;
    for (size_t i = 0; i < length; i++) {
      res = max(res, dp_l[i] + dp_r[i] - heights[i]);
    }
    return res;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
