// 137. Single Number II

int singleNumber(vector<int>& nums)
{
  int ret = 0;
  for (int i = 0; i < 32; ++i) {
    int count = 0;
    for (auto n : nums)
      if (n >> i & 1) count++;
    if (count % 3)
      ret += 1 << i;
  }
  return ret;
}

// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.



// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99
