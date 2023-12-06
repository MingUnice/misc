// 215. Kth Largest Element in an Array

// heap: 151ms
int findKthLargest(vector<int>& nums, int k)
{
  size_t n = nums.size();
  if (k > n) return -1;

  std::function<void(int)> heapify = [&](int i) {
    n = nums.size();
    int l = i * 2 + 1, r = i * 2 + 2;
    if (l >= n) return;
    int mi = l;
    if (r < n && nums[r] > nums[l])
      mi = r;
    if (nums[i] >= nums[mi]) return;
    std::swap(nums[i], nums[mi]);
    heapify(mi);
  };

  for (int i = n - 1; i >= 0; --i)
    heapify(i);
  for (int i = 0; i < k - 1; ++i) {
    std::swap(nums.back(), nums[0]);
    nums.pop_back();
    heapify(0);
  }
  return nums[0];
}


// std 64ms
int findKthLargest(vector<int>& nums, int k)
{
  std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>());
  return nums[k - 1];
}


// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?



// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4
