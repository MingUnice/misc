// 279. Perfect Squares



int numSquares(int n)
{
  std::vector<int> dp(n + 1, INT32_MAX);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int k = 1; k <= std::sqrt(i); ++k) {
      dp[i] = std::min(dp[i], dp[i - k * k] + 1);
    }
  }
  return dp[n];
}



// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.



// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
