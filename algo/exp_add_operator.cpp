// 282. Expression Add Operators

std::vector<std::string> addOperators(std::string nums, int target)
{
  const size_t n = nums.size();
  std::vector<std::string> ret;
  std::function<void(int, std::string, long, long)> dfs =
    [&](int pos, std::string exp, long prev, long cur) {
      if (pos == n) {
        if (cur == target) ret.push_back(exp);
        return;
      }
      for (int l = 1; l <= n - pos; ++l) {
        std::string rhs = nums.substr(pos, l);
        if (rhs[0] == '0' && rhs.size() != 1) break;
        long val = std::stol(rhs);
        if (val > INT_MAX) break;
        if (pos == 0) {
          dfs(l, rhs, val, val);
          continue;
        }
        dfs(pos + l, exp + '+' + rhs, val, cur + val);
        dfs(pos + l, exp + '-' + rhs, -val, cur - val);
        dfs(pos + l, exp + '*' + rhs, prev * val, cur - prev + prev * val);
      }
    };
  dfs(0, "", 0, 0);
  return ret;
}

// Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

// Note that operands in the returned expressions should not contain leading zeros.



// Example 1:

// Input: num = "123", target = 6
// Output: ["1*2*3","1+2+3"]
// Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
// Example 2:

// Input: num = "232", target = 8
// Output: ["2*3+2","2+3*2"]
// Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
// Example 3:

// Input: num = "3456237490", target = 9191
// Output: []
// Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.


// Constraints:

// 1 <= num.length <= 10
// num consists of only digits.
// -231 <= target <= 231 - 1
