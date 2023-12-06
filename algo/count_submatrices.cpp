// 1504. Count Submatrices With All Ones

int numSubmat(vector<vector<int>> &mat)
{
  const int n = mat.size(), m = mat[0].size();
  // number of sub matrices with top-left at (row, col)
  auto sub = [&](int row, int col) {
    int count = 0, m_ = m;
    for (int r = row; r < n; ++r)
      for (int c = col; c < m_; ++c)
	if (mat[r][c]) ++count;
	else m_ = c;
    return count;
  };
  int res = 0;
  for (int r = 0; r < n; ++r)
    for (int c = 0; c < m; ++c)
      res += sub(r, c);
  return res;
}


// Given an m x n binary matrix mat, return the number of submatrices that have all ones.



// Example 1:


// Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
// Output: 13
// Explanation:
// There are 6 rectangles of side 1x1.
// There are 2 rectangles of side 1x2.
// There are 3 rectangles of side 2x1.
// There is 1 rectangle of side 2x2.
// There is 1 rectangle of side 3x1.
// Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
