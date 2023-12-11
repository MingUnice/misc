// 1306. Jump Game III

bool canReach(vector<int>& nums, int start)
{
  const size_t n = nums.size();
  int count = 0;
  std::vector<int> reached(n);
  std::function<void(int)> dfs = [&](int p) {
    if (reached[p]) return;
    if (nums[p] == 0) count++;
    if (count != 0) return;
    reached[p] = 1;
    if (p - nums[p] >= 0) dfs(p - nums[p]);
    if (p + nums[p] < n) dfs(p + nums[p]);
  };
  dfs(start);
  if (count != 0) return true;
  return false;
}

// Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

// Notice that you can not jump outside of the array at any time.



// Example 1:

// Input: arr = [4,2,3,0,3,1,2], start = 5
// Output: true
// Explanation:
// All possible ways to reach at index 3 with value 0 are:
// index 5 -> index 4 -> index 1 -> index 3
// index 5 -> index 6 -> index 4 -> index 1 -> index 3
// Example 2:

// Input: arr = [4,2,3,0,3,1,2], start = 0
// Output: true
// Explanation:
// One possible way to reach at index 3 with value 0 is:
// index 0 -> index 4 -> index 1 -> index 3
// Example 3:

// Input: arr = [3,0,2,1,2], start = 2
// Output: false
// Explanation: There is no way to reach at index 1 with value 0.
