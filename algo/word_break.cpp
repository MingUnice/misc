// 139. Word Break

bool wordBreak(string s, vector<string>& w)
{
  std::set<std::string> wset;
  for (auto it : w)
    wset.insert(it);
  const size_t n = s.size();
  std::vector<bool> dp(n + 1, false);
  dp[0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (dp[j]) {
        std::string tmp = s.substr(j, i - j);
        if (wset.count(tmp)) {
          dp[i] = true;
          break;
        }
      }
    }
  }
  return dp[n];
}

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.



// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
