#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Interval {
  size_t l, r; //[l, r]

  Interval(size_t l, size_t r) : l(l), r(r) {}

  int getLength() const {
    return int(r - l + 1);
  }
  bool operator<(const Interval interval) const {
    return l < interval.l;
  }
  bool operator>(const Interval interval) const {
    return l > interval.l;
  }
  Interval operator+(const Interval interval) const {
    auto res = Interval(min(l, interval.l), max(r, interval.r));
    return res;
  }
};

class Solution {
 private:
  deque<Interval> q_start, q_swap;

  string str;
  size_t length;

  bool expand(Interval &interval) {
    auto res = false;
    while (true) {
      auto l = int(interval.l) - 1;
      auto r = int(interval.r) + 1;

      if (l == -1 || r == length) break;
      if (str[l] != '(' || str[r] != ')') break;

      interval.l = l;
      interval.r = r;
      res = true;
    }
    return res;
  }

  bool merge(deque<Interval> &q,
             deque<Interval> &q_temp) {
    auto res = false;
    auto lst_interval = q.front();
    q.pop_front();

    if (expand(lst_interval)) {
      res = true;
    }
    while (!q.empty()) {
      auto cur_interval = q.front();
      q.pop_front();

      if (cur_interval.l == lst_interval.r + 1) {
        res = true;
        lst_interval = cur_interval + lst_interval;
      } else {
        if (expand(cur_interval)) {
          res = true;
          q.push_front(cur_interval);
        } else {
          q_temp.push_back(lst_interval);
          lst_interval = cur_interval;
        }
      }
    }
    q_temp.push_back(lst_interval);
    return res;
  }

 public:
  int longestValidParentheses(string s) {
    str = s;
    length = s.length();
    if (length == 0) return 0;

    for (auto i = 0; i < length - 1; i++) {
      if (s[i] == '(' && s[i + 1] == ')') {
        q_start.emplace_back(i, i + 1);
      }
    }

    if (q_start.empty()) return 0;

    auto flag = true;
    while (true) {
      auto merge_res = false;
      if (flag) merge_res = merge(q_start, q_swap);
      else merge_res = merge(q_swap, q_start);

      if (!merge_res) break;
      flag = !flag;
    }

    auto res = 0;
    while (!q_start.empty()) {
      res = max(q_start.front().getLength(), res);
      q_start.pop_front();
    }
    while (!q_swap.empty()) {
      res = max(q_swap.front().getLength(), res);
      q_swap.pop_front();
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.longestValidParentheses(")(())))(())())") << endl;
  return 0;
}
