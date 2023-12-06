// 560. Subarray Sum Equals K


int subarraySum(vector<int>& nums, int k)
{
  int ret = 0;
  const size_t n = nums.size();
  std::unordered_map<long long, int> prefix_sum;
  prefix_sum[0] = 1;
  long long cur = 0;
  for (int i = 0; i < n; ++i) {
    cur += nums[i];
    if (prefix_sum.count(cur - k))
      ret += prefix_sum.at(cur - k);
    prefix_sum[cur]++;
  }
  return ret;
}


// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2
