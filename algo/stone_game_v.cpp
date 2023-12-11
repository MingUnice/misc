// 1563. Stone Game V

int stoneGameV(vector<int>& nums)
{
  const size_t n = nums.size();
  std::vector<int> prefix_sum(n + 1);
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cur += nums[i];
    prefix_sum[i + 1] = cur;
  }
  std::vector<std::vector<int>> cache(n, std::vector<int>(n, -1));
  std::function<int(int, int)> dp = [&](int l, int r) {
    if (l >= r) return 0;
    if (l == r - 1) return std::min(nums[l], nums[r]);
    if (cache[l][r] != -1) return cache[l][r];
    int res = 0;
    for (int i = l; i <= r - 1; ++i) {
      int sum_l = prefix_sum.at(i + 1) - prefix_sum.at(l);
      int sum_r = prefix_sum.at(r + 1) - prefix_sum.at(i + 1);
      if (sum_l < sum_r)
        res = std::max(res, dp(l, i) + sum_l);
      else if (sum_l > sum_r)
        res = std::max(res, dp(i + 1, r) + sum_r);
      else
        res = std::max(res, std::max(dp(l, i), dp(i + 1, r)) + sum_l);
    }
    cache[l][r] = res;
    return res;
  };
  return dp(0, n - 1);
}


// There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

// In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

// The game ends when there is only one stone remaining. Alice's is initially zero.

// Return the maximum score that Alice can obtain.



// Example 1:

// Input: stoneValue = [6,2,3,4,5,5]
// Output: 18
// Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
// In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
// The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.
// Example 2:

// Input: stoneValue = [7,7,7,7,7,7,7]
// Output: 28
// Example 3:

// Input: stoneValue = [4]
// Output: 0
