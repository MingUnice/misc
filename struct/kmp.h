#ifndef __KMP_H__
#define __KMP_H__

#include <string>
#include <vector>

// get the size of longest prefix which is also a suffix
std::vector<int> LongestPrefixSuffix(std::string s)
{
  const size_t n = s.size();
  std::vector<int> p(n, 0);
  int l = 0, r = 1;
  for (; r < n; ++r) {
    while (l > 0 && s[l] != s[r])
      l = p[l - 1];
    if (s[l] == s[r])
      p[r] = ++l;
  }
  return p;
}

// 
std::vector<int> Match(std::string s, std::string w)
{
  std::vector<int> ret;
  std::vector<int> p = LongestPrefixSuffix(w);
  const size_t m = s.size(), n = w.size();
  if (n > m) return ret;
  for (int i = 0, j = 0; i < m; ++i) {
    while (j > 0 && s[i] != w[j])
      j = p[j - 1];
    if (s[i] == w[j])
      ++j;
    if (j == n) {
      ret.push_back(i - n + 1);
      j = p[j - 1];
    }
  }
  return ret;
}

#endif
