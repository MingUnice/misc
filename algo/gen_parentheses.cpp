// 22. Generate Parentheses
// dfs

vector<string> generateParenthesis(int n)
{
  std::vector<std::string> ret;
  std::string cur;
  std::function<void(int, int)> dfs = [&](int l, int r) {
    if (l == 0 && r == 0) {
      ret.push_back(cur);
      return;
    }
    if (l > r) return;
    if (l > 0) {
      cur += "(";
      dfs(l - 1, r);
      cur.pop_back();
    }
    if (r > 0) {
      cur += ")";
      dfs(l, r - 1);
      cur.pop_back();
    }
  };
  dfs(n, n);
  return ret;
}

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
