// 56. Merge Intervals

bool CompareVec(const std::vector<int> &lhs, const std::vector<int> &rhs)
{
  return lhs[0] < rhs[0];
}

std::vector<std::vector<int>>
merge(std::vector<std::vector<int>> &v)
{
  std::sort(v.begin(), v.end(), CompareVec);
  std::vector<std::vector<int>> ret;
  for (int i = 0; i < v.size(); ++i) {
    int _begin = v[i][0];
    int _end = v[i][1];
    int j = i + 1;
    for (; j < v.size(); ++j) {
      if (v[j][0] > _end) break;
      if (v[j][1] > _end)
        _end = v[j][1];
      ++i;
    }
    ret.push_back({_begin, _end});
  }
  return ret;
}


// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
