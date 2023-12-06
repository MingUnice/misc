// 1573. Number of Ways to Split a String


long nCr(int n, int r)
{
  if (r == 0) return 1;
  if (r > n / 2) return nCr(n, n - r);
  long ret = 1;
  for (int k = 1; k <= r; ++k) {
    ret *= n - k + 1;
    ret /= k;
  }
  return ret;
}

int numWays(string s)
{
  const int n = s.size();
  int c = 0;
  for (int i = 0; i < n; ++i)
    if (s[i] == '1')
      c++;
  if (c % 3 != 0) return 0;
  if (c == 0)			// result = C(n - 1, 2)
    return nCr(n - 1, 2) % (long)(1e9 + 7);
  int c2 = 0;
  int idx1 = 0, idx2 = 0, idx3 = 0, idx4 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      c2++;
      if (c2 == c / 3)
        idx1 = i;
      if (c2 == c / 3 + 1)
        idx2 = i;
      if (c2 == 2 * c / 3)
        idx3 = i;
      if (c2 == 2 * c / 3 + 1) {
        idx4 = i;
        break;
      }
    }
  }
  return ((long long)idx2 - idx1) * ((long long)idx4 - idx3) % (long long)(1e9 + 7);
}


// Given a binary string s, you can split s into 3 non-empty strings s1, s2, and s3 where s1 + s2 + s3 = s.

// Return the number of ways s can be split such that the number of ones is the same in s1, s2, and s3. Since the answer may be too large, return it modulo 109 + 7.



// Example 1:

// Input: s = "10101"
// Output: 4
// Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
// "1|010|1"
// "1|01|01"
// "10|10|1"
// "10|1|01"
// Example 2:

// Input: s = "1001"
// Output: 0
// Example 3:

// Input: s = "0000"
// Output: 3
// Explanation: There are three ways to split s in 3 parts.
// "0|0|00"
// "0|00|0"
// "00|0|0"
