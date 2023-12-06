// 739. Daily Temperatures

vector<int> dailyTemperatures(vector<int>& nums)
{
  std::stack<int> stk;
  const size_t n = nums.size();
  std::vector<int> ret(n, 0);
  for (int i = 0; i < n; ++i) {
    int val = nums[i];
    while (!stk.empty()) {
      if (val <= nums[stk.top()]) break;
      ret[stk.top()] = i - stk.top();
      stk.pop();
    }
    stk.push(i);
  }
  return ret;
}


// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.



// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]
