// 150. Evaluate Reverse Polish Notation

int evalRPN(std::vector<std::string>& strs)
{
  int ret = 0;
  std::stack<int> stk;
  for (int i = 0; i < strs.size(); ++i) {
    std::string s = strs[i];
    if (s.size() == 1 && (s[0] == '+' ||
                          s[0] == '-' ||
                          s[0] == '*' ||
                          s[0] == '/')) {
      if (stk.size() < 2) return ret;
      int rhs = stk.top();
      stk.pop();
      int lhs = stk.top();
      stk.pop();
      int n;
      if (s[0] == '+' ) n = lhs + rhs;
      else if (s[0] == '-') n = lhs - rhs;
      else if (s[0] == '*') n = lhs * rhs;
      else if (s[0] == '/') n = lhs / rhs;
      stk.push(n);
      //printf("%d %d %d\n", lhs, rhs, n);
    } else {
      stk.push(std::stoi(s));
    }
  }
  return stk.top();
};

// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.


// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
// Example 3:

// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22
