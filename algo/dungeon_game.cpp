// 174. Dungeon Game

int calculateMinimumHP(vector<vector<int>>& nums)
{
  const size_t m = nums.size(), n = nums[0].size();
  std::vector<int> dp = nums[m - 1];
  auto need = [](int v) { return v < 0 ? -v : 0; };
  dp[n - 1] = need(dp[n - 1]);
  for (int j = n - 2; j >= 0; --j)
    dp[j] = need(dp[j] - dp[j + 1]);
  for (int i = m - 2; i >= 0; --i) {
    dp[n - 1] = need(nums[i][n - 1] - dp[n - 1]);
    for (int j = n - 2; j >= 0; --j) {
      dp[j] = need(nums[i][j] - std::min(dp[j], dp[j + 1]));
    }
    // for (auto it : dp)
    //   printf("%d ", it);
    // printf("\n");
  }
  return dp[0] + 1;
}

// The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

// The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

// Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

// To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

// Return the knight's minimum initial health so that he can rescue the princess.

// Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.



// Example 1:


// Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
// Output: 7
// Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
