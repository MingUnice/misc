// 1345. Jump Game IV

int minJumps(std::vector<int> &nums)
{
  const size_t n = nums.size();
  bool seen[n];
  memset(seen, 0, sizeof(seen));
  std::unordered_map<int, std::vector<int>> m;
  for (int i = 0; i < n; ++i) {
    m[nums[i]].push_back(i);
  }
  std::queue<int> q({0});
  int ret = 0;
  while (!q.empty()) {
    auto qsize = q.size();
    while (qsize--) {
      int i = q.front();
      q.pop();
      seen[i] = true;
      if (i == n - 1) return ret;
      if (i > 0 && !seen[i - 1])
        q.push(i - 1);
      if (i < n - 1 && !seen[i + 1])
        q.push(i + 1);
      if (m.count(nums[i]) == 0)
        continue;
      for (auto it : m[nums[i]]) {
        if (!seen[it]) q.push(it);
      }
      m.erase(nums[i]);
    }
    ret++;
  }
  return -1;
}

// Given an array of integers arr, you are initially positioned at the first index of the array.

// In one step you can jump from index i to index:

// i + 1 where: i + 1 < arr.length.
// i - 1 where: i - 1 >= 0.
// j where: arr[i] == arr[j] and i != j.
// Return the minimum number of steps to reach the last index of the array.

// Notice that you can not jump outside of the array at any time.



// Example 1:

// Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
// Output: 3
// Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
// Example 2:

// Input: arr = [7]
// Output: 0
// Explanation: Start index is the last index. You do not need to jump.
// Example 3:

// Input: arr = [7,6,9,6,9,6,9,7]
// Output: 1
// Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
