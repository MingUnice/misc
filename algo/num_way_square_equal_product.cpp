// 1577. Number of Ways Where Square of Number Is Equal to Product of Two Numbers


int numTriplets(vector<int> &nums1, vector<int> &nums2)
{
  auto solve = [](vector<int> &nums1, vector<int> &nums2) -> int {
    int res = 0;
    unordered_map<int, int> hmap;
    for (int y : nums2) ++hmap[y];
    for (long long x : nums1)
      for (const auto &[y, c] : hmap) {
        long long r = x * x / y;
        if (x * x % y || !hmap.count(r))
          continue;
        if (r == y)
          res += c * (c - 1);
        else res += c * hmap[r];
      }
    return res / 2;
  };

  return solve(nums1, nums2) + solve(nums2, nums1);
}

// Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2) under the following rules:

// Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
// Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.


// Example 1:

// Input: nums1 = [7,4], nums2 = [5,2,8,9]
// Output: 1
// Explanation: Type 1: (1, 1, 2), nums1[1]2 = nums2[1] * nums2[2]. (42 = 2 * 8).
// Example 2:

// Input: nums1 = [1,1], nums2 = [1,1,1]
// Output: 9
// Explanation: All Triplets are valid, because 12 = 1 * 1.
// Type 1: (0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2).  nums1[i]2 = nums2[j] * nums2[k].
// Type 2: (0,0,1), (1,0,1), (2,0,1). nums2[i]2 = nums1[j] * nums1[k].
// Example 3:

// Input: nums1 = [7,7,8,3], nums2 = [1,2,9,7]
// Output: 2
// Explanation: There are 2 valid triplets.
// Type 1: (3,0,2).  nums1[3]2 = nums2[0] * nums2[2].
// Type 2: (3,0,1).  nums2[3]2 = nums1[0] * nums1[1].
