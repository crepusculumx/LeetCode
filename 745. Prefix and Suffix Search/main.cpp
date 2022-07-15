#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TrieNode {
  unordered_map<char, shared_ptr<TrieNode>> children;
  set<int> indexes;
};

class WordFilter {
 private:
  shared_ptr<TrieNode> pre_root = make_shared<TrieNode>();
  shared_ptr<TrieNode> suf_root = make_shared<TrieNode>();

 public:
  WordFilter(vector<string> &words) {
    for (int i = 0; i < words.size(); i++) {
      string word = words[i];
      shared_ptr<TrieNode> cur_pre = pre_root;
      shared_ptr<TrieNode> cur_suf = suf_root;

      for (auto it = word.cbegin(); it != word.cend(); it++) {
        if (cur_pre->children.count(*it) == 0) {
          cur_pre->children[*it] = make_shared<TrieNode>();
        }
        cur_pre->children[*it]->indexes.insert(i);
        cur_pre = cur_pre->children[*it];
      }

      for (auto it = word.crbegin(); it != word.crend(); it++) {
        if (cur_suf->children.count(*it) == 0) {
          cur_suf->children[*it] = make_shared<TrieNode>();
        }
        cur_suf->children[*it]->indexes.insert(i);
        cur_suf = cur_suf->children[*it];
      }
    }
  }

  int f(string pref, string suff) {
    std::reverse(suff.begin(), suff.end());
    shared_ptr<TrieNode> cur_pre = pre_root;
    shared_ptr<TrieNode> cur_suf = suf_root;

    for (auto c : pref) {
      if (cur_pre->children.count(c) == 0) { return -1; }
      cur_pre = cur_pre->children[c];
    }

    for (auto c : suff) {
      if (cur_suf->children.count(c) == 0) { return -1; }
      cur_suf = cur_suf->children[c];
    }

    set<int> &s1 = cur_pre->indexes;
    set<int> &s2 = cur_suf->indexes;

    for (auto it = s1.crbegin(); it != s1.crend(); it++) {
      if (s2.count(*it)) return *it;
    }
    return -1;
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */

int main() {
  vector<string> v = {"apple"};
  WordFilter word_filter{v};
  word_filter.f("a", "e");
  return 0;
}
