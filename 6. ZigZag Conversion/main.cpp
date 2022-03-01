#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
  node() : value(0), coordinate(make_pair(0, 0)) {}
  node(char value, pair<int, int> coordinate) : value(value), coordinate(std::move(coordinate)) {}
  char value{};
  pair<int, int> coordinate;

  bool operator<(const node b) const {
    if (coordinate.second < b.coordinate.second) return true;
    if (coordinate.second == b.coordinate.second) {
      if (coordinate.first < b.coordinate.first) return true;
    }
    return false;
  }
};

enum mode {
  DOWN,
  UP
};

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;

    size_t length = s.length();
    vector<node> nodes(length);

    pair<int, int> cur_coordinate = make_pair(0, 0);
    mode cur_mode = DOWN;
    for (size_t i = 0; i < length; i++) {
      node cur_node = node(s[i], cur_coordinate);
      nodes[i] = cur_node;

      switch (cur_mode) {
        case DOWN:cur_coordinate = make_pair(cur_coordinate.first, cur_coordinate.second + 1);
          if (cur_coordinate.second == numRows) {
            cur_coordinate = make_pair(cur_coordinate.first + 1, numRows - 2);
            cur_mode = UP;
          }
          break;
        case UP:cur_coordinate = make_pair(cur_coordinate.first + 1, cur_coordinate.second - 1);
          if (cur_coordinate.second == -1) {
            cur_coordinate = make_pair(cur_coordinate.first - 1, 1);
            cur_mode = DOWN;
          }
          break;
      }
    }

    sort(nodes.begin(), nodes.end());

    string ans;
    for (auto &node : nodes) {
      ans += node.value;
    }
    return ans;
  }
};

int main() {
  return 0;
}
