#include "sort.h"
#include "utils.h"

#include <random>

void test(std::vector<int> vec, std::function<void(std::vector<int>&)> fn)
{
  auto begin_time = GetTime();
  fn(vec);
  auto end_time = GetTime();
  printf("elapsed time: %.2fs\n", (end_time - begin_time) / 1000.0);
  printf("%d\n", std::is_sorted(vec.begin(), vec.end()));
}

int main(int argc, char *argv[])
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1, 10000000);
  size_t n = 10000;
  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    nums[i] = distrib(gen);
  }
  
  std::vector<void(*)(std::vector<int>&)>
    functions = {
                 select_sort,
                 insert_sort,
                 bubble_sort,
                 merge_sort,
                 heap_sort,
                 bst_sort,
                 counting_sort,
                 quick_sort,
                 parallel_quick_sort
  };
  for (auto f : functions)
    test(nums, f);
  
  return 0;
}
