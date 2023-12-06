// 1671. Minimum Number of Removals to Make Mountain Array

int minimumMountainRemovals(vector<int>& nums)
{
  const auto n = nums.size();
  vector<int> LIS(n, 1); // LIS[i] := Longest increasing subseq ends with nums[i]
  vector<int> LDS(n, 1); // LDS[i] := Longest decreasing subseq starts with nums[i]
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < i; ++j) {
      if (nums[i] > nums[j])
        LIS[i] = std::max(LIS[i], LIS[j] + 1);
    }
  for (int i = n - 1; i >= 0; --i)
    for (int j = n - 1; j > i; --j) {
      if (nums[i] > nums[j])
        LDS[i] = std::max(LDS[i], LDS[j] + 1);
    }

  int res = n;
  for (int i = 0; i < n; ++i) {
    if (LIS[i] < 2 || LDS[i] < 2) continue;
    res = std::min(res, (int)(n - LIS[i] - LDS[i] + 1));
  }

  return res;
}


// You may recall that an array arr is a mountain array if and only if:

// arr.length >= 3
// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.



// Example 1:

// Input: nums = [1,3,1]
// Output: 0
// Explanation: The array itself is a mountain array so we do not need to remove any elements.
// Example 2:

// Input: nums = [2,1,1,5,6,2,3,1]
// Output: 3
// Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
