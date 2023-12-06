// 300. Longest Increasing Subsequence

int lengthOfLIS(vector<int>& nums)
{
  const size_t n = nums.size();
  std::vector<int> is;        // increase squence
  for (int i = 0; i < n; ++i) {
    int cur = nums[i];
    auto it = std::lower_bound(is.begin(), is.end(), cur);
    if (it == is.end()) {
      is.push_back(cur);
    } else {
      *it = cur;
    }
  }
  return is.size();
}

// Given an integer array nums, return the length of the longest strictly increasing
// subsequence
// .



// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
