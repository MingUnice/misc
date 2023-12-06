// 1690. Stone Game VII

int stoneGameVII(vector<int>& nums) {
  const size_t n = nums.size();

  // prefix sum : sum[l ~ r] = prefixSum[r + 1] - prefixSum[l]
  vector<int> prefixSum(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefixSum[i + 1] = prefixSum[i] + nums[i];
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int len = 2; len <= n; ++len) {
    for(int l = 0, r = l + len - 1; r < n; ++l, ++r) {
      dp[l][r] = std::max(prefixSum[r + 1] - prefixSum[l + 1] - dp[l + 1][r],
                          prefixSum[r] - prefixSum[l] - dp[l][r - 1]);
    }
  }
  return dp[0][n - 1];

}

int stoneGameVII(vector<int>& A) {
  const int n = A.size();
  vector<vector<int>> cache(n, vector<int>(n, INT_MAX));
  function<int(int, int, int)> dp = [&](int l, int r, int s) {
    if (l >= r) return 0;
    if (cache[l][r] == INT_MAX)
      cache[l][r] = max(s - A[r] - dp(l, r - 1, s - A[r]),
                        s - A[l] - dp(l + 1, r, s - A[l]));
    return cache[l][r];
  };
  return dp(0, n - 1, accumulate(begin(A), end(A), 0));
}

// dp[l ~ r] = max(sum[l+1 ~ r] - dp[l+1 ~ r], sum[l ~ r-1] - dp[l ~ r-1])

// Alice and Bob take turns playing a game, with Alice starting first.

// There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.

// Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's difference. Alice's goal is to maximize the difference in the score.

// Given an array of integers stones where stones[i] represents the value of the ith stone from the left, return the difference in Alice and Bob's score if they both play optimally.



// Example 1:

// Input: stones = [5,3,1,4,2]
// Output: 6
// Explanation:
// - Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
// - Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
// - Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
// - Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
// - Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
// The score difference is 18 - 12 = 6.
// Example 2:

// Input: stones = [7,90,5,1,100,10,10,2]
// Output: 122
