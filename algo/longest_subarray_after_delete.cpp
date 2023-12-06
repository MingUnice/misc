// 1493. Longest Subarray of 1's After Deleting One Element


int longestSubarray(vector<int> &nums)
{
  const int n = nums.size();
  vector<int> l(n), r(n);
  l[0] = nums[0];
  r[n - 1] = nums[n - 1];
  for (int i = 1; i < n; ++i) {
    l[i] = nums[i] * (l[i - 1] + 1);
    r[n - i - 1] = nums[n - i - 1] * (r[n - i] + 1);
  }
  int res = 0;
  for (int i = 1; i < n - 1; ++i) {
    res = max(res, l[i - 1] + r[i + 1]);
  }

  return res;
}


// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.



// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
// Example 3:

// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
