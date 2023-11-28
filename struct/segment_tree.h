#ifndef __SEGMENT_TREE_H__
#define __SEGMENT_TREE_H__

#include <vector>
#include <functional>

struct SegmentTree {
  struct Node {
    Node(size_t begin, size_t end, int sum,
          Node *left = nullptr, Node *right = nullptr) :
      begin_(begin), end_(end), sum_(sum),
      left_(left), right_(right) {}

    virtual ~Node()
    {
      if (left_) delete(left_);
      if (right_) delete(right_);
    }

    size_t begin_;
    size_t end_;
    int sum_;
    Node *left_;
    Node *right_;
  };
  SegmentTree() {}
  SegmentTree(std::vector<int> &data) : data_(data)
  {
    std::function<Node*(int, int)> build = [&](int l, int r) {
      if (l == r)
        return new Node(l, l, data_[l]);
      int mid = l + (r - l) / 2;
      auto pleft = build(l, mid);
      auto pright = build(mid + 1, r);
      return new Node(l, r, pleft->sum_ + pright->sum_, pleft, pright);
    };
    root_ = build(0, data_.size() - 1);
  }

  virtual ~SegmentTree()
  {
    if (root_) delete(root_);
  }

  void Update(size_t index, int val)
  {
    std::function<void(Node*)> f = [&](Node *n) {
      if (n->begin_ == n->end_ && n->begin_ == index) {
        n->sum_ = val;
        return;
      }
      int mid = n->begin_ + (n->end_ - n->begin_) / 2;
      if (index <= mid) f(n->left_);
      else f(n->right_);
      n->sum_ = n->left_->sum_ + n->right_->sum_;
    };
    f(root_);
  }

  int SumRange(size_t begin, size_t end)
  {
    std::function<int(Node *, int, int)> f = [&](Node *n, int l, int r) {
      if (n->begin_ == l && n->end_ == r) return n->sum_;
      int mid = n->begin_ + (n->end_ - n->begin_) / 2;
      if (mid >= r)
        return f(n->left_, l, r);
      else if (mid < l)
        return f(n->right_, l, r);
      else
        return f(n->left_, l, mid) + f(n->right_, mid + 1, r);
    };
    return f(root_, begin, end);
  }

  std::vector<int> data_;
  Node *root_;
};

#endif
