#include <iostream>
#include <queue>

using namespace std;

class MovingAverage {
 private:
  queue<int> q;
  int size = 0;
  int sum = 0;

 public:
  /** Initialize your data structure here. */
  explicit MovingAverage(int size) : size(size) {}

  double next(int val) {
    q.push(val);
    sum += val;
    if (q.size() > size) {
      sum -= q.front();
      q.pop();
    }

    return static_cast<double >(sum) / static_cast<double >(q.size());
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
