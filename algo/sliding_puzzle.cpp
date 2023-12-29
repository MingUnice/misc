// 773. Sliding Puzzle

int slidingPuzzle(std::vector<std::vector<int>> &nums)
{
  const size_t m = nums.size(), n = nums[0].size();
  std::string res, start;
  for (int i = 1; i < m * n; ++i)
    res += '0' + i;
  res += '0';
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      start += nums[i][j] + '0';
    }
  }
  if (res == start) return 0;
  std::set<std::string> seen{start};
  int steps = 0;
  std::queue<std::string> q;
  q.push(start);
  std::string cur;
  size_t pos;

  std::function<int(int, int)> bfs = [&](int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n)
      return 0;
    size_t cur_pos = n * x + y;
    std::string tmp(cur);
    std::swap(tmp[pos], tmp[cur_pos]);
    if (tmp == res) return steps;
    if (seen.count(tmp))
      return 0;
    seen.insert(tmp);
    q.push(tmp);
    return 0;
  };

  while (!q.empty()) {
    ++steps;
    size_t qsize = q.size();
    while (qsize--) {
      cur = q.front();
      q.pop();
      pos = cur.find('0');
      int x = pos / n, y = pos % n;
      int ret;
      if (ret = bfs(x - 1, y)) return ret;
      if (ret = bfs(x + 1, y)) return ret;
      if (ret = bfs(x, y - 1)) return ret;
      if (ret = bfs(x, y + 1)) return ret;
    }
  }
  return -1;
}

// On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

// The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

// Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.



// Example 1:


// Input: board = [[1,2,3],[4,0,5]]
// Output: 1
// Explanation: Swap the 0 and the 5 in one move.
// Example 2:


// Input: board = [[1,2,3],[5,4,0]]
// Output: -1
// Explanation: No number of moves will make the board solved.
// Example 3:


// Input: board = [[4,1,2],[5,0,3]]
// Output: 5
// Explanation: 5 is the smallest number of moves that solves the board.
// An example path:
// After move 0: [[4,1,2],[5,0,3]]
// After move 1: [[4,1,2],[0,5,3]]
// After move 2: [[0,1,2],[4,5,3]]
// After move 3: [[1,0,2],[4,5,3]]
// After move 4: [[1,2,0],[4,5,3]]
// After move 5: [[1,2,3],[4,5,0]]
