// 1568. Minimum Number of Days to Disconnect Island


int minDays(std::vector<std::vector<int>> &g)
{
  const size_t m = g.size(), n = g[0].size();
  std::vector<std::vector<int>> seen(m, std::vector<int>(n, 0));
  std::function<void(int, int)> dfs = [&](int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return;
    if (g[x][y] == 0) return;
    if (seen[x][y]++) return;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
  };
  std::function<bool(void)> is_dis = [&]() {
    for (auto &v : seen) std::fill(v.begin(), v.end(), 0);
    int count = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] && !seen[i][j]) {
          dfs(i, j);
          count++;
          if (count > 1) return true;
        }
      }
    }
    if (count == 0) return true;
    return false;
  };
  if (is_dis()) return 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!g[i][j]) continue;
      g[i][j] = 0;
      if (is_dis()) return 1;
      g[i][j] = 1;
    }
  }
  return 2;
}

// You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

// The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

// In one day, we are allowed to change any single land cell (1) into a water cell (0).

// Return the minimum number of days to disconnect the grid.



// Example 1:


// Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

// Output: 2
// Explanation: We need at least 2 days to get a disconnected grid.
// Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
// Example 2:


// Input: grid = [[1,1]]
// Output: 2
// Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
