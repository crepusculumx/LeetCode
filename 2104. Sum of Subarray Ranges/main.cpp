#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// res = sum(max_t[i] * n[i] - min_t[i] * n[i])
// min_t[i] = min_l[i] + min_r[i] + min_l[i] * min_r[i]
class Solution {
 private:
  int length;
 public:
  long long subArrayRanges(vector<int> &nums) {
    length = static_cast<int>(nums.size());

    auto min_l = vector<int>(length, 0);
    auto min_r = vector<int>(length, 0);
    auto max_l = vector<int>(length, 0);
    auto max_r = vector<int>(length, 0);

    auto s_min = stack<int>();
    auto s_max = stack<int>();

    s_min.push(-1);
    s_max.push(-1);
    for (int i = 0; i < length; i++) {
      while (s_min.top() != -1 && nums[s_min.top()] > nums[i]) {
        s_min.pop();
      }
      min_l[i] = s_min.top();
      s_min.push(i);

      while (s_max.top() != -1 && nums[s_max.top()] < nums[i]) {
        s_max.pop();
      }
      max_l[i] = s_max.top();
      s_max.push(i);
    }

    while (!s_min.empty())s_min.pop();
    while (!s_max.empty())s_max.pop();

    s_min.push(length);
    s_max.push(length);

    for (int i = length - 1; i >= 0; i--) {
      while (s_min.top() != length && nums[s_min.top()] >= nums[i]) {
        s_min.pop();
      }
      min_r[i] = s_min.top();
      s_min.push(i);

      while (s_max.top() != length && nums[s_max.top()] <= nums[i]) {
        s_max.pop();
      }
      max_r[i] = s_max.top();
      s_max.push(i);
    }

    long long ans = 0;
    for (int i = 0; i < length; i++) {
      ans += static_cast<long long>(nums[i]) * (i - max_l[i]) * (max_r[i] - i);
      ans -= static_cast<long long>(nums[i]) * (i - min_l[i]) * (min_r[i] - i);
    }

    return ans;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
