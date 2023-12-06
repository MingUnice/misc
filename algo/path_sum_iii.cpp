// 437. Path Sum III

int pathSum(TreeNode* root, int total)
{
  int ret = 0;
  // map [k, v] : the count v of prefix sum == k
  std::unordered_map<long long, int> counts{{0, 1}};
  std::function<void(TreeNode *, long long)> f =
    [&](TreeNode *n, long long cur_sum) {
      if (!n) return;
      cur_sum += n->val;
      ret += counts[cur_sum - total];
      counts[cur_sum]++;
      f(n->left, cur_sum);
      f(n->right, cur_sum);
      counts[cur_sum]--;
    };
  f(root, 0);
  return ret;
}

// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).



// Example 1:


// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.
// Example 2:

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: 3
