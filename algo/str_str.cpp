// 28. Find the Index of the First Occurrence in a String
// sliding window

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

int strStr(std::string s, std::string w)
{
  std::vector<int> p = LongestPrefixSuffix(w);
  const size_t lens = s.size(), lenw = w.size();
  if (lenw > lens) return -1;
  for (int i = 0, j = 0; i < lens; ++i) {
    while (j > 0 && s[i] != w[j])
      j = p[j - 1];
    if (s[i] == w[j])
      ++j;
    if (j == lenw)
      return i - lenw + 1;
  }
  return -1;
}

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.



// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
