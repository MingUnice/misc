// 994. Rotting Oranges

int orangesRotting(vector<vector<int>>& g)
{
  if (g.empty()) return 0;
  const size_t m = g.size(), n = g[0].size();
  std::queue<std::pair<int, int>> q;
  int ret = 0, count = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (g[i][j] == 2) q.push({i, j});
      if (g[i][j] == 1) count++;
    }
  }
  if (count == 0) return 0;

  std::function<void(int, int)> change = [&](int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return;
    if (g[x][y] != 1) return;
    count--;
    g[x][y] = 2;
    q.push({x, y});
  };

  while (!q.empty()) {
    int ncur = q.size();
    while (ncur--) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      change(x - 1, y);
      change(x + 1, y);
      change(x, y - 1);
      change(x, y + 1);
    }
    ret++;
    if (count == 0) break;
  }
  return count ? -1 : ret;
}



// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.



// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
