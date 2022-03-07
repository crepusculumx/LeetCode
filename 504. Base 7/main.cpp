#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
 public:
  int num_ = 0;
  int sum = 0;
  static int pow7(int i) {
    int p[10] = {1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 40353607};
    return p[i];
  }

  int two(int l, int r, int k) {//[l, r] NOLINT(misc-no-recursion)
    if (r - l <= 10000) {
      for (int i = r; i >= l; i--) {
        int temp = pow7(k) * i;
        if (sum + temp <= num_) {
          sum += temp;
          return i;
        }
      }
    }
    int mid = (l + r) / 2;
    int temp = pow7(k) * mid;
    if (sum + temp > num_) return two(l, mid - 1, k);
    else if (sum + temp == num_) return mid;
    else return two(mid, r, k);
  }

 public:
  string convertToBase7(int num) {
    auto flag = false;
    if (num < 0) {
      flag = true;
      num = -num;
    }
    num_ = num;

    int res_num = 0;
    for (int i = 9; i >= 0; i--) {
      res_num *= 10;
      int t = two(0, 9, i);
      res_num += t;
    }

    if (flag) res_num = -res_num;
    return to_string(res_num);
  }
};

int main() {
  Solution s;
  cout << s.convertToBase7(100);
  return 0;
}
