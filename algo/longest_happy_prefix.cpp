// 1392. Longest Happy Prefix


std::string longestPrefix(std::string s)
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
  if (p[n - 1] == 0) return "";
  return s.substr(0, p[n - 1]);
}


// A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

// Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.



// Example 1:

// Input: s = "level"
// Output: "l"
// Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
// Example 2:

// Input: s = "ababab"
// Output: "abab"
// Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.
