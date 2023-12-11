// 1775. Equal Sum Arrays With Minimum Number of Operations

int minOperations(vector<int>& nums1, vector<int>& nums2)
{
  const size_t n1 = nums1.size(), n2 = nums2.size();
  if (6 * std::min(n1, n2) < std::max(n1, n2))
    return -1;
  int s1 = std::accumulate(nums1.begin(), nums1.end(), 0);
  int s2 = std::accumulate(nums2.begin(), nums2.end(), 0);
  int diff = std::abs(s1 - s2);
  if (s1 == s2) return 0;
  const std::vector<int> &b = s1 > s2 ? nums1 : nums2;
  const std::vector<int> &l = s1 > s2 ? nums2 : nums1;
  std::vector<int> interval;
  for (int i = 0; i < b.size(); ++i) {
    interval.push_back(b.at(i) - 1);
  }
  for (int i = 0; i < l.size(); ++i) {
    interval.push_back(6 - l.at(i));
  }
  std::sort(interval.begin(), interval.end(), std::greater<int>());

  // for (auto i : interval)
  //   printf("%d ", i);
  // printf("\n");

  int ret = 0;
  while (diff > 0) {
    diff -= interval[ret++];
  }
  return ret;
}

// You are given two arrays of integers nums1 and nums2, possibly of different lengths. The values in the arrays are between 1 and 6, inclusive.

// In one operation, you can change any integer's value in any of the arrays to any value between 1 and 6, inclusive.

// Return the minimum number of operations required to make the sum of values in nums1 equal to the sum of values in nums2. Return -1​​​​​ if it is not possible to make the sum of the two arrays equal.

 

// Example 1:

// Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
// Output: 3
// Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed.
// - Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
// - Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
// - Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].
// Example 2:

// Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
// Output: -1
// Explanation: There is no way to decrease the sum of nums1 or to increase the sum of nums2 to make them equal.
// Example 3:

// Input: nums1 = [6,6], nums2 = [1]
// Output: 3
// Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed. 
// - Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
// - Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
// - Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].
