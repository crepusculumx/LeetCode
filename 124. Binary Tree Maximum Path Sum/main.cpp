#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 private:
  int ans = INT_MIN;
  int dfs(TreeNode *tree_node) { // NOLINT(misc-no-recursion)
    int left_res = 0, right_res = 0;

    if (tree_node->left != nullptr) left_res = dfs(tree_node->left);
    if (tree_node->right != nullptr) right_res = dfs(tree_node->right);

    if(left_res < 0)  left_res = 0;
    if(right_res < 0) right_res = 0;

    ans = max(ans, left_res + right_res + tree_node->val);

    return max(left_res, right_res) + tree_node->val;
  }

 public:
  int maxPathSum(TreeNode *root) {
    dfs(root);
    return ans;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
