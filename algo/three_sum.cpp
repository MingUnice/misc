// 15. 3Sum

std::vector<std::vector<int>> threeSum(std::vector<int> &vec) {
  std::vector<std::vector<int>> ret;
  int len = vec.size();
  std::sort(vec.begin(), vec.end());
  for (int i = 0; i < len - 2; ++i) {
    int target = -vec[i];
    if (target < 0) break;
    int l = i + 1, r = len - 1;
    while (l < r) {
      int lv = vec[l], rv = vec[r];
      int sum = lv + rv;
      if (sum < target) {
        ++l;
      } else if (sum > target) {
        --r;
      } else {
        ret.push_back({vec[i], lv, rv});
        while (vec[l] == lv && l < r)
          ++l;
        while (vec[r] == rv && l < r)
          --r;
      }
    } // end while l < r
    while (i < len - 2 && vec[i + 1] == vec[i]) ++i;
  } // end for i
  return ret;
}

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.



// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
