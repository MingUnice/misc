// 200. Number of Islands

int numIslands(vector<vector<char>>& grid)
{
  if (grid.empty()) return 0;
  const size_t m = grid.size(), n = grid[0].size();
  std::map<std::pair<int, int>, int> lands;
  int l = 0;
  std::function<void(int,int)> f = [&](int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return;
    if (lands.count({x, y}) && lands[{x, y}] != 0) return;
    if (grid[x][y] == '1') {
      lands[{x, y}] = l;
      //printf("%d %d is land %d\n", x, y, l);
      f(x - 1, y);
      f(x + 1, y);
      f(x, y - 1);
      f(x, y + 1);
    }
  };
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '1') {
        if (lands.count({i, j}) == 0 || lands[{i, j}] == 0) {
          ++l;
          //printf("%d\n", l);
          f(i, j);
        }
      }
    }
  }
  return l;
}

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
