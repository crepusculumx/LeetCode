#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int arrayNesting(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == -1)continue;
      if (nums.size() - i < ans) return ans;
      int cur_p = i;
      int cur_ans = 0;
      while (nums[cur_p] != -1) {
        cur_ans++;
        int next_p = nums[cur_p];
        nums[cur_p] = -1;
        cur_p = next_p;
      }
      ans = max(ans, cur_ans);
    }
    return ans;
  }
};

int main() {
  vector<int> arr{5, 4, 0, 3, 1, 6, 2};
  std::cout << Solution().arrayNesting(arr);
  return 0;
}
