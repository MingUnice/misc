// 786. K-th Smallest Prime Fraction

vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k)
{
  const size_t n = nums.size();
  float l = 0, r = 1.0;
  while (l < r) {
    float m = (l + r) / 2;
    float max_frac = 0.0;
    int begin, end, cnt = 0;
    for (int i = 0, j = 1; i < n - 1; ++i) {
      while (j < n && nums[i] > m * nums[j])
        ++j;
      if (j == n) break;
      cnt += n - j;
      float frac = (float)nums[i] / nums[j];
      if (frac > max_frac) {
        begin = i;
        end = j;
        max_frac = frac;
      }
    }
    if (cnt == k)
      return {nums[begin], nums[end]};
    else if (cnt > k)
      r = m;
    else
      l = m;
  }
  return {};
}


// You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

// For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

// Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].



// Example 1:

// Input: arr = [1,2,3,5], k = 3
// Output: [2,5]
// Explanation: The fractions to be considered in sorted order are:
// 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
// The third fraction is 2/5.
// Example 2:

// Input: arr = [1,7], k = 1
// Output: [1,7]
