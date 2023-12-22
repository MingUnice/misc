// 934. Shortest Bridge

int shortestBridge(vector<vector<int>>& nums)
{
  int ret = 0;
  const size_t n = nums.size(), m = nums[0].size();
  std::queue<std::pair<int, int>> first_island;
  std::function<void(int, int)> get_first_island = [&](int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || nums[x][y] != 1)
      return;
    nums[x][y] = 2;
    first_island.push({x, y});
    get_first_island(x - 1, y);
    get_first_island(x + 1, y);
    get_first_island(x, y - 1);
    get_first_island(x, y + 1);
  };
  bool found = false;
  for (int i = 0; i < m && !found; ++i) {
    for (int j = 0; j < n && !found; ++j) {
      if (nums[i][j]) {
        get_first_island(i, j);
        found = true;
      }
    }
  }
  std::function<bool(int, int)> is_connected = [&](int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || nums[x][y] == 2)
      return false;
    if (nums[x][y] == 1)
      return true;
    nums[x][y] = 2;
    first_island.push({x, y});
    return false;
  };
  while (!first_island.empty()) {
    size_t k = first_island.size();
    while (k--) {
      int x = first_island.front().first;
      int y = first_island.front().second;
      first_island.pop();
      bool b = is_connected(x - 1, y) ||
        is_connected(x + 1, y) ||
        is_connected(x, y - 1) ||
        is_connected(x, y + 1);
      if (b) return ret;
    }
    ++ret;
  }
  return -1;
}


// You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

// An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

// You may change 0's to 1's to connect the two islands to form one island.

// Return the smallest number of 0's you must flip to connect the two islands.



// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: 1
// Example 2:

// Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2
// Example 3:

// Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1


// Constraints:

// n == grid.length == grid[i].length
// 2 <= n <= 100
// grid[i][j] is either 0 or 1.
// There are exactly two islands in grid.
