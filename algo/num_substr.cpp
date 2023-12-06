// 1513. Number of Substrings With Only 1s

int numSub(string s)
{
  const int n = s.size();
  constexpr int MOD = 1e9 + 7;
  unordered_map<int, int> len;	// len -> number
  int l = 0;
  for (const char &c : s) {
    if (c == '1')
      l++;
    else if (l != 0) {
      len[l]++;
      l = 0;
    }
  }
  if (l != 0) len[l]++;
  int res = 0;
  for (const auto &[i, m] : len) {
    // printf("%d %d\n", i, m);
    res += (long long)i * (i + 1) / 2 * m % MOD;
  }

  return res;
}

// Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.



// Example 1:

// Input: s = "0110111"
// Output: 9
// Explanation: There are 9 substring in total with only 1's characters.
// "1" -> 5 times.
// "11" -> 3 times.
// "111" -> 1 time.
// Example 2:

// Input: s = "101"
// Output: 2
// Explanation: Substring "1" is shown 2 times in s.
// Example 3:

// Input: s = "111111"
// Output: 21
// Explanation: Each substring contains only 1's characters.
