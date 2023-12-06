// 1505. Minimum Possible Integer After at Most K Adjacent Swaps On Digits

class FenwickTree
{
public:
  FenwickTree(int n) : sums_(n + 1, 0) {}

  void update(int i, int delta)
  {
    while (i < sums_.size()) {
      sums_[i] += delta;
      i += lowbit(i);
    }
  }

  int query(int i) const
  {
    int sum = 0;
    while (i > 0) {
      sum += sums_[i];
      i -= lowbit(i);
    }
    return sum;
  }

private:
  static inline int lowbit(int x)
  {
    return x & (-x);
  }

  vector<int> sums_;
};


class Solution {
public:
  string minInteger(string num, int k)
  {
    const int n = num.size();
    vector<queue<int>> pos(10);
    for (int i = 0; i < n; ++i)
      pos[num[i] - '0'].push(i);

    // number of int moved before position i = query(i)
    FenwickTree tree(n);
    vector<int> used(n);
    string res;
    while (k > 0 && res.size() < n) {
      for (int d = 0; d < 10; ++d) {
        if (pos[d].empty()) continue;
        const int i = pos[d].front();
        const int cost = i - tree.query(i);
        if (cost > k) continue;
        k -= cost;
        res.push_back('0' + d);
        tree.update(i + 1, 1);
        used[i] = true;
        pos[d].pop();
        break;
      }
    }
    for (int i = 0; i < n; ++i)
      if (!used[i]) res.push_back(num[i]);
    return res;
  }
};

// You are given a string num representing the digits of a very large integer and an integer k. You are allowed to swap any two adjacent digits of the integer at most k times.

// Return the minimum integer you can obtain also as a string.



// Example 1:


// Input: num = "4321", k = 4
// Output: "1342"
// Explanation: The steps to obtain the minimum integer from 4321 with 4 adjacent swaps are shown.
// Example 2:

// Input: num = "100", k = 1
// Output: "010"
// Explanation: It's ok for the output to have leading zeros, but the input is guaranteed not to have any leading zeros.
// Example 3:

// Input: num = "36789", k = 1000
// Output: "36789"
// Explanation: We can keep the number without any swaps.
