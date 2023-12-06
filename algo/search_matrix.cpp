// 74. Search a 2D Matrix

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
  if (matrix.empty()) return false;
  const size_t m = matrix.size(), n = matrix[0].size();
  int l = 0, r = m * n;
  while (l < r) {
    int mid = l + (r - l) / 2;
    int v = matrix[mid / n][mid % n];
    if (v == target) return true;
    if (v > target) r = mid;
    else l = mid + 1;
  }
  return false;
}


// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.



// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
