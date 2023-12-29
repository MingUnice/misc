// 377. Combination Sum IV

int combinationSum4(vector<int>& nums, int target)
{
  const size_t n = nums.size();
  std::vector<int> cache(target + 1, -1);
  cache[0] = 1;
  std::function<int(int)> dp = [&](int t) {
    if (t < 0) return 0;
    if (cache[t] != -1) return cache[t];
    int ret = 0;
    for (const auto &i : nums)
      ret += dp(t - i);
    return cache[t] = ret;
  };
  return dp(target);
}

// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

// The test cases are generated so that the answer can fit in a 32-bit integer.

// Example 1:

// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.
// Example 2:

// Input: nums = [9], target = 3
// Output: 0
