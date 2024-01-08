// 1799. Maximize Score After N Operations

class Solution {
public:
  int maxScore(vector<int>& nums)
  {
    const size_t n = nums.size();
    std::vector<int> cache(1 << n);
    std::function<int(int)> dp = [&](int mask) {
      if (mask == 0) return 0;
      if (cache.at(mask) > 0) return cache.at(mask);
      int &res = cache[mask];
      int k = (n - __builtin_popcount(mask)) / 2 + 1;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (mask & (1 << i) && mask & (1 << j))
            res = std::max(res,
                           k * std::gcd(nums[i], nums[j]) +
                           dp(mask ^ (1 << i) ^ (1 << j)));
        }
      }
      return res;
    };
    return dp((1 << n) - 1);
  }
};

// You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

// In the ith operation (1-indexed), you will:

// Choose two elements, x and y.
// Receive a score of i * gcd(x, y).
// Remove x and y from nums.
// Return the maximum score you can receive after performing n operations.

// The function gcd(x, y) is the greatest common divisor of x and y.



// Example 1:

// Input: nums = [1,2]
// Output: 1
// Explanation: The optimal choice of operations is:
// (1 * gcd(1, 2)) = 1
// Example 2:

// Input: nums = [3,4,6,8]
// Output: 11
// Explanation: The optimal choice of operations is:
// (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
// Example 3:

// Input: nums = [1,2,3,4,5,6]
// Output: 14
// Explanation: The optimal choice of operations is:
// (1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
