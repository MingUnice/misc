// 39. Combination Sum
// dfs

vector<vector<int>> combinationSum(vector<int>& can, int t)
{
  std::sort(can.begin(), can.end());
  std::vector<std::vector<int>> ret;
  std::vector<int> cur;
  const size_t n = can.size();
  std::function<void(int, int)> dfs = [&](int l, int remain) {
    if (remain == 0) {
      ret.push_back(cur);
      return;
    }
    for (int i = l ; i < n; ++i) {
      if (can[i] > remain) break;
      cur.push_back(can[i]);
      dfs(i, remain - can[i]);
      cur.pop_back();
    }
  };
  dfs(0, t);
  return ret;
}



// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
// frequency
//  of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []
