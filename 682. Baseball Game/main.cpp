#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:
  int calPoints(vector<string> &ops) {
    stack<int> s;
    int t0 = 0, t1 = 0;
    for (const auto &op : ops) {
      switch (op[0]) {
        case 'C':s.pop();
          break;
        case 'D':s.push(s.top() * 2);
          break;
        case '+':t1 = s.top();
          s.pop();
          t0 = s.top();
          s.push(t1);
          s.push(t0 + t1);
          break;
        default:s.push(stoi(op));
          break;
      }
    }

    int res = 0;
    while (!s.empty()) {
      res += s.top();
      s.pop();
    }
    return res;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
