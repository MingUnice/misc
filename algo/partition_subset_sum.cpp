// 416. Partition Equal Subset Sum
// dp

class Solution {
public:
  bool canPartition(std::vector<int> &nums)
  {
    const size_t n = nums.size();
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    sum /= 2;
    std::vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for (int k = 0; k < n; ++k) {
      int val = nums[k];
      for (int i = sum; i >= 0; --i) {
        if (dp[i]) {
          if (i + val <= sum) {
            dp[i + val] = true;
            if (i + val == sum) return true;
          }
        }
      }
    }
    return dp[sum];
  }
};


// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.



// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
