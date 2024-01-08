// 763. Partition Labels

std::vector<std::vector<int>>
merge(std::vector<std::vector<int>> &v)
{
  std::sort(v.begin(), v.end(),
            [](const std::vector<int> &lhs, const std::vector<int> &rhs) {
              return lhs[0] < rhs[0];
            });
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

std::vector<int> partitionLabels(std::string s)
{
  if (s.empty()) return {};
  const size_t n = s.size();
  std::map<char, std::pair<int, int>> m;
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (m.count(c)) {
      m[c].second = i;
    } else {
      m[c] = {i, i};
    }
  }
  std::vector<std::vector<int>> vec;
  for (auto it : m)
    vec.push_back({it.second.first, it.second.second});
  auto vec2 = merge(vec);
  std::vector<int> ret;
  for (auto it : vec2)
    ret.push_back(it[1] - it[0] + 1);
  return ret;
}



// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

// Return a list of integers representing the size of these parts.



// Example 1:

// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
// Example 2:

// Input: s = "eccbbbbdec"
// Output: [10]
