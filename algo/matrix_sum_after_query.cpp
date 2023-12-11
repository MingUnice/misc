// 2718. Sum of Matrix After Queries

long long matrixSumQueries(int n, vector<vector<int>> &m)
{
  long long ret = 0;
  long long row_sum = 0, col_sum = 0;
  bool row_done[n], col_done[n];
  memset(row_done, 0, sizeof(row_done));
  memset(col_done, 0, sizeof(col_done));
  const size_t msize = m.size();
  for (int i = msize - 1; i >= 0; --i) {
    int type = m[i][0];
    int index = m[i][1];
    int val = m[i][2];
    if (type == 0) {
      if (row_done[index]) m[i][0] = -1;
      else row_done[index] = true;
    } else if (type == 1) {
      if (col_done[index]) m[i][0] = -1;
      else col_done[index] = true;
    }
  }
  for (int i = 0; i < msize; ++i) {
    int type = m[i][0];
    int index = m[i][1];
    int val = m[i][2];
    if (type == 0) {
      row_sum += val;
      ret += n * val;
      ret -= col_sum;
    } else if (type == 1) {
      col_sum += val;
      ret += n * val;
      ret -= row_sum;
    }
  }
    
  return ret;
}


// You are given an integer n and a 0-indexed 2D array queries where queries[i] = [typei, indexi, vali].

// Initially, there is a 0-indexed n x n matrix filled with 0's. For each query, you must apply one of the following changes:

// if typei == 0, set the values in the row with indexi to vali, overwriting any previous values.
// if typei == 1, set the values in the column with indexi to vali, overwriting any previous values.
// Return the sum of integers in the matrix after all queries are applied.

 

// Example 1:


// Input: n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
// Output: 23
// Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 23. 
// Example 2:


// Input: n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
// Output: 17
// Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 17.
