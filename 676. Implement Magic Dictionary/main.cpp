#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

using namespace std;

struct TrieNode {
  unordered_map<char, shared_ptr<TrieNode>> children;
  bool end = false;

};

class MagicDictionary {
 private:
  shared_ptr<TrieNode> root_ptr = make_shared<TrieNode>();

 public:
  MagicDictionary() = default;

  void buildDict(vector<string> dictionary) {
    for (auto &s : dictionary) {
      shared_ptr<TrieNode> cur_ptr = root_ptr;
      for (auto c : s) {
        if (cur_ptr->children.find(c) == cur_ptr->children.end()) {
          cur_ptr->children[c] = make_shared<TrieNode>();
        }
        cur_ptr = cur_ptr->children[c];
      }
      cur_ptr->end = true;
    }
  }

  bool dfs(const shared_ptr<TrieNode> &cur_node_ptr, string_view str, int str_p, bool can_change) {
    if (cur_node_ptr->end && str_p == str.length() && !can_change) return true;
    char c = str[str_p];

    const auto it = cur_node_ptr->children.find(c);
    bool can_find = !(it == cur_node_ptr->children.cend());
    if (!can_find && !can_change) { return false; }
    if (!can_find && can_change) {
      for (const auto &next_it : cur_node_ptr->children) {
        bool res = dfs(next_it.second, str, str_p + 1, false);
        if (res) return res;
      }
      return false;
    }
    if (can_find && !can_change) {
      return dfs(it->second, str, str_p + 1, false);
    }
    if (can_find && can_change) {
      for (const auto &next_it : cur_node_ptr->children) {
        bool res;
        if (next_it.first == c) { res = dfs(next_it.second, str, str_p + 1, true); }
        else { res = dfs(next_it.second, str, str_p + 1, false); }
        if (res) return res;

      }
      return false;
    }
    return false;
  }

  bool search(string searchWord) {
    return dfs(root_ptr, searchWord, 0, true);
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main() {
  MagicDictionary magic_dictionary;
  magic_dictionary.buildDict({"hello", "hallo", "leetcode"});
//  magic_dictionary.search("hello");
  cout << magic_dictionary.search("hallo");
//  magic_dictionary.search("hell");
//  magic_dictionary.search("leetcoded");
  return 0;
}
