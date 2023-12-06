// 438. Find All Anagrams in a String

vector<int> findAnagrams(string s, string p)
{
  const size_t n1 = s.size(), n2 = p.size();
  if (n2 > n1) return {};
  std::vector<int> ret;
  std::unordered_map<char, int> freq;
  std::function<bool(void)> is_done = [&freq]() {
    for (auto it : freq) {
      if (it.second > 0) return false;
    }
    return true;
  };
  for (char c : p) freq[c]++;
  std::unordered_map<char, int> freq_backup = freq;
  for (int i = 0; i < n2; ++i) {
    char c = s[i];
    if (freq.count(c)) freq[c]--;
  }
  if (is_done()) ret.push_back(0);

  for (int i = 1; i <= n1 - n2; ++i) {
    char c1 = s[i - 1], c2 = s[i + n2 - 1];
    if (freq_backup.count(c1)) freq[c1]++;
    freq[c2]--;
    if (is_done()) ret.push_back(i);
  }

  return ret;
}


// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab"
