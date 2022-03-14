#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
 private:
  unordered_map<string, int> m;
  int n1, n2;
 public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    n1 = static_cast<int>(list1.size());
    n2 = static_cast<int>(list2.size());
    for (auto i = 0; i < n1; i++) {
      m[list1[i]] = i;
    }

    auto res = vector<string>();
    auto score = INT32_MAX;
    for (auto i = 0; i < n2; i++){
      auto it = m.find(list2[i]);
      if(it == m.end()) continue;
      if(it->second + i < score){
        score = it->second + i;
        res.clear();
        res.emplace_back(it->first);
      }else if(it->second + i == score){
        res.emplace_back(it->first);
      }
    }
    return res;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
