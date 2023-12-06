// 322. Coin Change


int coinChange(std::vector<int> &vec, int sum)
{
  std::vector<int> dp(sum + 1, INT32_MAX);
  dp[0] = 0;
  for (int i = 1; i <= sum; ++i) {
    for (auto n : vec) {
      if (n > i) continue;
      if (dp[i - n] != INT32_MAX &&
          dp[i - n] + 1 < dp[i])
        dp[i] = dp[i - n] + 1;
    }
  }
  if (dp[sum] == INT32_MAX) return -1;
  return dp[sum];
}


// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.



// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
