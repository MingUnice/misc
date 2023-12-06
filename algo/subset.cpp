// 78. Subsets

vector<vector<int>> subsets(vector<int>& nums)
{
  const size_t n = nums.size();
  std::vector<std::vector<int>> ret;
  std::vector<int> cur;
  std::function<void(int)> dfs = [&](int d) {
    ret.push_back(cur);
    if (d == n) return;
    for (int i = d; i < n; ++i) {
      cur.push_back(nums[i]);
      dfs(i + 1);
      cur.pop_back();
    }
  };
  dfs(0);
  return ret;
}

// Given an integer array nums of unique elements, return all possible
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.



// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
