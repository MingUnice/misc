// 260. Single Number III


vector<int> singleNumber(vector<int>& nums)
{
  std::vector<int> ret;
  const size_t n = nums.size();
  int two_xor = 0;
  for (auto num : nums)
    two_xor ^= num;
  for (int i = 0; i < 32; ++i) {
    int mask = 1 << i;
    if (mask & two_xor) {
      // mask 位置上 n1 为1, n2 为0
      int n1 = 0, n2 = 0;
      for (auto num : nums) {
        if (mask & num) n1 ^=num;
        else n2 ^= num;
      }
      ret.push_back(n1);
      ret.push_back(n2);
      break;
    }
  }
  return ret;
}


// Companies
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.



// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.
// Example 2:

// Input: nums = [-1,0]
// Output: [-1,0]
// Example 3:

// Input: nums = [0,1]
// Output: [1,0]
