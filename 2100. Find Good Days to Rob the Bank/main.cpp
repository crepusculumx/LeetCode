#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  size_t length = 0;
  vector<int> up, down;
 public:
  vector<int> goodDaysToRobBank(vector<int> &security, int time) {
    length = security.size();
    up.resize(length, 0);
    down.resize(length, 0);

    for (size_t i = 1; i < length; i++) {
      if (security[i] <= security[i - 1]) {
        down[i] = down[i - 1] + 1;
      } else {
        down[i] = 0;
      }
    }

    for (int i = (int)length - 2; i >= 0; i--) {
      if (security[i] <= security[i + 1]) {
        up[i] = up[i + 1] + 1;
      } else {
        up[i] = 0;
      }
    }

    auto res = vector<int>();
    for(size_t i = 0; i < length; i++){
      if(up[i] >= time && down[i] >= time){
        res.emplace_back(i);
      }
    }
    return res;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
