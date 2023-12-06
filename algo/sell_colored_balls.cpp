// 1648. Sell Diminishing-Valued Colored Balls

int maxProfit(vector<int> &nums, int orders)
{
  const int MOD = 1e9 + 7;
  const int n = nums.size();
  long long l = 0, r = *max_element(nums.begin(), nums.end());
  long long s = 0;
  while (l < r) {
    int mid = (l + r) / 2;
    s = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] > mid)
        s += nums[i] - mid;
    }
    if (orders > s)
      r = mid;
    else
      l = mid + 1;
  }

  long long res = 0;
  long long re = orders;
  for (int i = 0; i < n; ++i) {
    if (nums[i] > l) {
      re -= nums[i] - l;
      res += (nums[i] + l + 1) * (nums[i] - l) / 2;
    }
  }
  res += (long long)re * l;

  return (int)(res % MOD);
}

// You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.

// The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that color you currently have in your inventory. For example, if you own 6 yellow balls, the customer would pay 6 for the first yellow ball. After the transaction, there are only 5 yellow balls left, so the next yellow ball is then valued at 5 (i.e., the value of the balls decreases as you sell more to the customer).

// You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color that you initially own. You are also given an integer orders, which represents the total number of balls that the customer wants. You can sell the balls in any order.

// Return the maximum total value that you can attain after selling orders colored balls. As the answer may be too large, return it modulo 109 + 7.



// Example 1:


// Input: inventory = [2,5], orders = 4
// Output: 14
// Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 times (5 + 4 + 3).
// The maximum total value is 2 + 5 + 4 + 3 = 14.
// Example 2:

// Input: inventory = [3,5], orders = 6
// Output: 19
// Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 times (5 + 4 + 3 + 2).
// The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.
