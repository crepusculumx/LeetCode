#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

constexpr int MAX_N = 50 + 7;
int memo[MAX_N][MAX_N][MAX_N * 2]{};

class Solution {
 private:
  size_t N{0};

  int dfs(vector<vector<int>> &grid, int x_1, int x_2, int k) {
    pair<int, int> p1 = make_pair(x_1, k - x_1);
    pair<int, int> p2 = make_pair(x_2, k - x_2);
    auto is_out_of_range = [](pair<int, int> pos) { return pos.first < 0 || pos.second < 0; };
    auto get_grid_by_pos = [&grid](pair<int, int> pos) { return grid[pos.first][pos.second]; };

    if (is_out_of_range(p1) || is_out_of_range(p2)) return -1;
    if (p1 == make_pair(0, 0) && p2 == make_pair(0, 0))
      return memo[x_1][x_2][k] = get_grid_by_pos(p1);

    if (memo[x_1][x_2][k] != INT_MIN) return memo[x_1][x_2][k];

    if (get_grid_by_pos(p1) == -1 || get_grid_by_pos(p2) == -1)return memo[x_1][x_2][k] = -1;

    int res1 = dfs(grid, x_1 - 1, x_2, k - 1);
    int res2 = dfs(grid, x_1 - 1, x_2 - 1, k - 1);
    int res3 = dfs(grid, x_1, x_2 - 1, k - 1);
    int res4 = dfs(grid, x_1, x_2, k - 1);

    if (res1 == -1 && res2 == -1 && res3 == -1 && res4 == -1)return memo[x_1][x_2][k] = -1;

    int cur_res;
    if (p1 == p2) { cur_res = get_grid_by_pos(p1); }
    else { cur_res = get_grid_by_pos(p1) + get_grid_by_pos(p2); }

    return memo[x_1][x_2][k] = cur_res + max(max(res1, res2), max(res3, res4));
  }

 public:
  int cherryPickup(vector<vector<int>> &grid) {
    N = grid.size();
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N * 2; k++) {
          memo[i][j][k] = INT_MIN;
        }
      }
    }

    return max(0, dfs(grid, N - 1, N - 1, 2 * N - 2));
  }
};

int main() {
  Solution s;

  vector<vector<int>> arr = {{1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1},
                             {1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1},
                             {-1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, -1, 1, -1, 1, 1},
                             {1, 1, 1, 1, 1, -1, -1, 1, 1, 1, -1, 1, -1, 1, -1, 1, 1, 1, -1, -1},
                             {1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, -1, 1},
                             {1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, -1, 1, 1, 1},
                             {1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1},
                             {-1, 1, 1, 1, 1, 1, 1, -1, 1, -1, 1, -1, 1, 1, 1, 1, 1, 1, 1, -1},
                             {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
                             {-1, 1, -1, 1, -1, -1, -1, 1, 1, 1, 1, -1, -1, 1, -1, 1, 0, 1, 1, 1},
                             {-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, -1, 1, 1, -1, -1},
                             {1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {0, 1, 1, -1, 1, 1, 1, 1, -1, 1, -1, 1, 1, 1, -1, -1, -1, 1, 1, 1},
                             {1, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1, -1, 1, 1, 1, 1, 1, 1, -1, 1},
                             {1, 1, 1, -1, 1, 1, 1, -1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 1, -1, 1, 1, -1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, -1, 0, 1},
                             {-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, 1}};
  cout << s.cherryPickup(arr);
  return 0;
}
