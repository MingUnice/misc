// 1649. Create Sorted Array through Instructions

class FenwickTree {
public:
  FenwickTree(int n) : sums_(n + 1, 0) {}

  void update(int i, int delta)
  {
    while (i < sums_.size()) {
      sums_[i] += delta;
      i += lowbit(i);
    }
  }

  int query(int i)
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


int createSortedArray(vector<int>& instructions)
{
  const int n = instructions.size();
  long long res = 0;
  FenwickTree tree(1e5);
  for (int i = 0; i < n; ++i) {
    int lt = tree.query(instructions[i] - 1);
    int gt = i - tree.query(instructions[i]);
    // std::cout << lt << " " << gt << endl;
    res += std::min(lt, gt);
    tree.update(instructions[i], 1);
  }
  return res % (int)(1e9 + 7);
}


// Given an integer array instructions, you are asked to create a sorted array from the elements in instructions. You start with an empty container nums. For each element from left to right in instructions, insert it into nums. The cost of each insertion is the minimum of the following:

// The number of elements currently in nums that are strictly less than instructions[i].
// The number of elements currently in nums that are strictly greater than instructions[i].
// For example, if inserting element 3 into nums = [1,2,3,5], the cost of insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is greater than 3) and nums will become [1,2,3,3,5].

// Return the total cost to insert all elements from instructions into nums. Since the answer may be large, return it modulo 109 + 7



// Example 1:

// Input: instructions = [1,5,6,2]
// Output: 1
// Explanation: Begin with nums = [].
// Insert 1 with cost min(0, 0) = 0, now nums = [1].
// Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
// Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
// Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
// The total cost is 0 + 0 + 0 + 1 = 1.
// Example 2:

// Input: instructions = [1,2,3,6,5,4]
// Output: 3
// Explanation: Begin with nums = [].
// Insert 1 with cost min(0, 0) = 0, now nums = [1].
// Insert 2 with cost min(1, 0) = 0, now nums = [1,2].
// Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].
// Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].
// Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].
// Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].
// The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.
