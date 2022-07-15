#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> s;
    for (auto aster : asteroids) {
      bool alive = true;
      while (alive && aster < 0 && !s.empty() && s.top() > 0) {
        alive = (s.top() < -aster);
        if (s.top() <= -aster) {
          s.pop();
        }
      }
      if (alive) {
        s.push(aster);
      }
    }

    vector<int> res;
    while (!s.empty()) {
      res.push_back(s.top());
      s.pop();
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
