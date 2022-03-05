#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  int length = 0;
 public:
  int findLUSlength(string a, string b) {
    if (a == b) return -1;
    return (int) max(a.length(), b.length());
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
