// 79. Word Search
// dfs

bool exist(vector<vector<char>> &g, string word)
{
  if (g.empty()) return false;
  const size_t m = g.size();
  const size_t n = g[0].size();
  std::function<bool(int, int, int)> dfs = [&](int d, int x, int y) {
    if (x < 0 || x > m - 1 || y < 0 || y > n - 1 || g[x][y] != word[d])
      return false;
    if (d == word.size() - 1) return true;
    char c = g[x][y];
    g[x][y] = 0;
    bool b = dfs(d + 1, x - 1, y) ||
      dfs(d + 1, x + 1, y) ||
      dfs(d + 1, x, y - 1) ||
      dfs(d + 1, x, y + 1);
    g[x][y] = c;
    return b;
  };
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (dfs(0, i, j))
        return true;
  return false;
}



// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.



// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
