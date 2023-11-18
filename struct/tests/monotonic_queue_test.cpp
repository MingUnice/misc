#include "monotonic_queue.h"

#include <vector>

#include "stdio.h"

// there is a sliding window of size k
// each time the sliding window moves right by one position
// return the max value of each window
std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
  std::vector<int> ret;
  MonotonicQueue<int> q([](const int& lhs, const int& rhs) {
                          return lhs < rhs; });
  const size_t n = nums.size();
  for (int i = 0; i < n; ++i) {
    q.push(nums[i]);
    if (i >= k - 1) {
      ret.push_back(q.top());
      if (nums[i - k + 1] == q.top())
        q.pop();
    }
  }
  return ret;
}

int main(int argc, char *argv[])
{
  std::vector<int> nums {3, 1, -1, -3, 5, 3, 6, 7};
  auto ret = maxSlidingWindow(nums, 3);
  for (auto i : ret)
    printf("%d ", i);
  printf("\n");
    
  return 0;
}
