// 1497. Check If Array Pairs Are Divisible by k

bool canArrange(vector<int> &nums, int k)
{
  vector<int> f(k);
  for (int i : nums)
    ++f[(i % k + k) % k];
  for (int i = 1; i < k / 2 + 1; ++i)
    if (f[i] != f[k - i]) return false;
  return f[0] % 2 == 0;
}

// Given an array of integers arr of even length n and an integer k.

// We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

// Return true If you can find a way to do that or false otherwise.



// Example 1:

// Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
// Output: true
// Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
// Example 2:

// Input: arr = [1,2,3,4,5,6], k = 7
// Output: true
// Explanation: Pairs are (1,6),(2,5) and(3,4).
// Example 3:

// Input: arr = [1,2,3,4,5,6], k = 10
// Output: false
// Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
