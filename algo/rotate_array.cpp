// 189. Rotate Array

void rotate(std::vector<int> &nums, int k) {
  size_t vec_size = nums.size();
  std::vector<int> ret(vec_size);
  for (size_t i = 0; i < vec_size; ++i) {
    int index = i - k;
    while (index < 0)
      index += vec_size;
    ret[i] = nums[index];
  }
  nums = ret;
}


// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation:
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
