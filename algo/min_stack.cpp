// 155. Min Stack

class MinStack {
public:
  MinStack() {}

  void push(int val)
  {
    data_.push(val);
    if (min_cache_.empty() ||
        min_cache_.top() >= val)
      min_cache_.push(val);
  }

  int getMin()
  {
    if (min_cache_.empty())
      return data_.top();
    return min_cache_.top();
  }

  void pop()
  {
    if (!min_cache_.empty() &&
        min_cache_.top() == data_.top())
      min_cache_.pop();
    data_.pop();
  }

  int top()
  {
    return data_.top();
  }

  std::stack<int> data_;
  std::stack<int> min_cache_;
};

// Companies
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.



// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
