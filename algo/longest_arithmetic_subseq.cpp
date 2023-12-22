// 1218. Longest Arithmetic Subsequence of Given Difference

// dp[i] := max length of sequence ends with x
// dp[x] = max(0, dp[x – diff]) + 1

int longestSubsequence(vector<int>& nums, int diff)
{
  int ret = 1;
  const size_t n = nums.size();
  std::unordered_map<int, int> dp;
  for (auto i : nums) {
    dp[i] = dp[i - diff] + 1;
    ret = std::max(ret, dp[i]);
  }
  return ret;
}

// Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

// A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: arr = [1,2,3,4], difference = 1
// Output: 4
// Explanation: The longest arithmetic subsequence is [1,2,3,4].
// Example 2:

// Input: arr = [1,3,5,7], difference = 1
// Output: 1
// Explanation: The longest arithmetic subsequence is any single element.
// Example 3:

// Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
// Output: 4
// Explanation: The longest arithmetic subsequence is [7,5,3,1].
