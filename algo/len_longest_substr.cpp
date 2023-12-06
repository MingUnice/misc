// 3. Longest Substring Without Repeating Characters
// record prev char position

int lengthOfLongestSubstring(string s) {
  const size_t n = s.size();
  std::vector<int> idx(128, -1);
  int ret = 0;
  for (int l = 0, r = 0; r < n; ++r) {
    l = std::max(l, idx[s[r]] + 1);
    ret = std::max(ret, r - l + 1);
    idx[s[r]] = r;
  }
  return ret;
}

// Given a string s, find the length of the longest
// substring
//  without repeating characters.



// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
