// 152. Maximum Product Subarray

int maxProduct(std::vector<int> &nums)
{
  if (nums.empty()) return 0;
  int ret = nums[0], l = nums[0], h = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    int p = nums[i];
    if (p < 0) std::swap(l, h);
    l = std::min(p, l * p);
    h = std::max(p, h * p);
    ret = std::max(ret, h);
  }

  return ret;
}

// Given an integer array nums, find a
// subarray
//  that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.



// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
