#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validUtf8(vector<int> &data) {
    int cnt = 0;
    for (auto i : data) {
      if (cnt) {
        if ((i & 0xC0) == 0x80) cnt--;
        else return false;
      } else if ((i & 0xE0) == 0xC0) cnt = 1;
      else if ((i & 0xF0) == 0xE0)cnt = 2;
      else if ((i & 0xF8) == 0xF0) cnt = 3;
      else if ((i & 0x80) != 0) return false;
    }
    return !cnt;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
