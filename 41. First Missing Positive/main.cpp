#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  void move(vector<int> &nums, size_t p) { // NOLINT(misc-no-recursion)
    if (nums[p] < 0 || nums[p] >= nums.size()) {
      nums[p] = 0;
      return;
    }
    while (nums[p] != p) {
      if (nums[nums[p]] == nums[p]) {
        nums[p] = 0;
        return;
      }
      swap(nums[nums[p]], nums[p]);
      move(nums, p);
    }
  }
 public:
  int firstMissingPositive(vector<int> &nums) {
    auto have_n_flag = false;
    for (auto n : nums) {
      if (n == nums.size()) {
        have_n_flag = true;
        break;
      }
    }
    for (size_t i = 0; i < nums.size(); i++) {
      move(nums, i);
    }
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i] == 0) return static_cast<int>(i);
    }

    if (have_n_flag) return static_cast<int>(nums.size() + 1);;
    return static_cast<int>(nums.size());
  }
};

int main() {
  Solution s;
  vector<int> v{2, 2, 2, 2, 2};
  cout << s.firstMissingPositive(v);
  return 0;
}
