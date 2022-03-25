#include <iostream>
#include <vector>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Node {
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};
class Solution {
 private:
  vector<int> res;

  void dfs(Node *n) { // NOLINT(misc-no-recursion)
    res.emplace_back(n->val);
    for (auto &c : n->children) {
      dfs(c);
    }
  }
 public:
  vector<int> preorder(Node *root) {
    if (root == nullptr) return {};

    dfs(root);
    return res;
  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
