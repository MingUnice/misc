#ifndef __SORT_H__
#define __SORT_H__

#include <vector>
#include <functional>
#include <algorithm>
#include <set>
#include <future>

#include <stdio.h>

// non stable
// time: n^2
// space: 1
void select_sort(std::vector<int> &nums)
{
  const size_t n = nums.size();
  if (n <= 1) return;
  for (int i = 0; i < n; ++i) {
    int min = i;
    for (int j = i + 1; j < n; ++j) {
      if (nums[j] < nums[min])
        min = j;
    }
    if (min != i)
      std::swap(nums[i], nums[min]);
  }
}

// stable
// time: n^2
// space: 1
void insert_sort(std::vector<int> &nums)
{
  const size_t n = nums.size();
  if (n <= 1) return;
  for (int i = 1; i < n; ++i) {
    int tmp = nums[i];
    int j;
    for (j = i - 1; j >= 0; --j) {
      if (tmp < nums[j])
        nums[j + 1] = nums[j];
      else
        break;
    }
    nums[j + 1] = tmp;
  }
}

// stable
// time: n^2
// space: 1
void bubble_sort(std::vector<int> &nums)
{
  const size_t n = nums.size();
  if (n <= 1) return;
  for (int i = n - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (nums[j] > nums[j + 1])
        std::swap(nums[j], nums[j + 1]);
    }
  }
}

// stable
// time: nlogn
// space: n
void merge_sort(std::vector<int> &nums)
{
  const size_t n = nums.size();
  if (n <= 1) return;
  std::vector<int> tmp(n);
  std::function<void(int, int)> fn =
    [&](int l, int r) {
      if (l + 1 >= r) return;
      int m = l + (r - l) / 2;
      fn(l, m);
      fn(m, r);
      int i1 = l, i2 = m, index = 0;
      while (i1 < m || i2 < r)
	if (i2 == r || (i1 < m && nums[i1] < nums[i2]))
	  tmp[index++] = nums[i1++];
	else
	  tmp[index++] = nums[i2++];
      std::copy(tmp.begin(), tmp.begin() + index, nums.begin() + l);
    };
  fn(0, n);
}


// non stable
// time: nlogn
// space: 1
void heap_sort(std::vector<int> &nums)
{
  // std::make_heap(nums.begin(), nums.end());
  // std::sort_heap(nums.begin(), nums.end());
  const size_t n = nums.size();
  if (n <= 1) return;
  auto heapify =
    [&](int i, int e) {
      while (i <= e) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int j = i;
        if (l <= e && nums[l] > nums[j])
          j = l;
        if (r <= e && nums[r] > nums[j])
          j = r;
        if (j == i) break;
        std::swap(nums[i], nums[j]);
        std::swap(i, j);
      }
   };
  for (int i = n / 2; i >= 0; --i)
    heapify(i, n - 1);
  for (int i = n - 1; i >= 1; --i) {
    std::swap(nums[0], nums[i]);
    heapify(0, i - 1);
  }
}

// stable
// time: nlogn ~ n^2
// space: n
void bst_sort(std::vector<int> &nums)
{
  const size_t n = nums.size();
  if (n <= 1) return;
  std::multiset<int> s(nums.begin(), nums.end());
  nums = std::vector<int>(s.begin(), s.end());
}

// stable
// time: n + m
// space: n + m
void counting_sort(std::vector<int> &nums)
{
  const size_t n = nums.size();
  if (n <= 1) return;
  auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
  int l = *min_it, r = *max_it;
  std::vector<int> count(r - l + 1);
  for (auto i : nums)
    count[i - l]++;
  int index = 0;
  for (int i = 0; i < count.size(); ++i) {
    while (count[i]--)
      nums[index++] = i + l;
  }
}

// non stable
// time: nlogn ~ n^2
// space: logn
void quick_sort(std::vector<int> &nums)
{
  const size_t n = nums.size();
  if (n <= 1) return;
  std::function<void(int, int)> fn =
    [&](int l, int r) {
      if (l >= r) return;
      int begin = l, end = r;
      int p = nums[l + (r - l) / 2];
      while (l <= r) {
        while (nums[l] < p)
          ++l;
        while (nums[r] > p)
          --r;
        if (l <= r)
          std::swap(nums[l++], nums[r--]);
      }
      fn(begin, r);
      fn(l, end);
    };
  fn(0, n - 1);
}

void parallel_quick_sort(std::vector<int> &nums)
{
  const size_t n = nums.size();
  if (n <= 1) return;
  std::function<void(int, int)> fn =
    [&](int l, int r) {
      if (l >= r) return;
      int begin = l, end = r;
      int p = nums[l + (r - l) / 2];
      while (l <= r) {
        while (nums[l] < p)
          ++l;
        while (nums[r] > p)
          --r;
        if (l <= r)
          std::swap(nums[l++], nums[r--]);
      }
      fn(begin, r);
      fn(l, end);
    };
  std::function<void(int, int)> parallel_fn =
    [&](int l, int r) {
      if (l >= r) return;
      if (r - l > 1000) {
        fn(l, r);
        return;
      }
      int begin = l, end = r;
      int p = nums[l + (r - l) / 2];
      while (l <= r) {
        while (nums[l] < p)
          ++l;
        while (nums[r] > p)
          --r;
        if (l <= r)
          std::swap(nums[l++], nums[r--]);
      }
      auto f1 = std::async(std::launch::async, [&](){ parallel_fn(begin, r); });
      auto f2 = std::async(std::launch::async, [&](){ parallel_fn(l, end); });
      f1.wait();
      f2.wait();
    };
  parallel_fn(0, n - 1);
}


#endif
