// 1569. Number of Ways to Reorder Array to Get Same BST


// C(l + r, l) * ways(l) * ways(r)
int numOfWays(vector<int>& nums)
{
  const int n = nums.size();
  constexpr int MOD = 1e9 + 7;

  vector<vector<long>> cnk(n + 1, vector<long>(n + 1, 1));
  // C(n, k) = C(n - 1, k) + C(n - 1, k - 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j < i; ++j)
      cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % MOD;

  function<long(const vector<int>&)> tree = [&](const vector<int> &vec) -> long {
    const int v = vec.size();
    if (v <= 2) return 1;
    vector<int> left, right;
    for (int i = 1; i < v; ++i)
      if (vec[i] < vec[0]) left.push_back(vec[i]);
      else right.push_back(vec[i]);
    long ans = cnk[v - 1][left.size()];
    // ans *= tree(left) % MOD * tree(right);
    ans = (ans * tree(left)) % MOD;
    ans = (ans * tree(right)) % MOD;
    return ans;
  };

  return (int)((tree(nums) - 1) % MOD);
}


// Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

// For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
// Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

// Since the answer may be very large, return it modulo 109 + 7.



// Example 1:


// Input: nums = [2,1,3]
// Output: 1
// Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.
// Example 2:


// Input: nums = [3,4,5,1,2]
// Output: 5
// Explanation: The following 5 arrays will yield the same BST:
// [3,1,2,4,5]
// [3,1,4,2,5]
// [3,1,4,5,2]
// [3,4,1,2,5]
// [3,4,1,5,2]
// Example 3:


// Input: nums = [1,2,3]
// Output: 0
// Explanation: There are no other orderings of nums that will yield the same BST.
