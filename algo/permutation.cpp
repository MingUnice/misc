// 46. Permutations
// dfs

vector<vector<int>> permute(vector<int>& nums)
{
  const size_t n = nums.size();
  std::vector<std::vector<int>> ret;
  std::vector<int> cur;
  std::vector<bool> used(n, false);
  std::function<void(int)> dfs = [&](int d) {
    if (d == n) {
      ret.push_back(cur);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (used[i]) continue;
      used[i] = true;
      cur.push_back(nums[i]);
      dfs(d + 1);
      cur.pop_back();
      used[i] = false;
    }
  };
  dfs(0);
  return ret;
}


// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
