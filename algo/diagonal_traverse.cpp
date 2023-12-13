// 498. Diagonal Traverse

vector<int> findDiagonalOrder(vector<vector<int>>& mat)
{
  const size_t m = mat.size(), n = mat[0].size();
  std::vector<std::vector<int>> matrix(m + n -1);
  std::vector<int> ret;
  int sign = -1;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      matrix[i + j].push_back(mat[i][j]);
    }
  }
  for (auto vec : matrix) {
    if (sign > 0)
      ret.insert(ret.end(), vec.begin(), vec.end());
    else
      ret.insert(ret.end(), vec.rbegin(), vec.rend());
    sign *= -1;
  }
  return ret;
}


// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

// Example 1:


// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]
// Example 2:

// Input: mat = [[1,2],[3,4]]
// Output: [1,2,3,4]
