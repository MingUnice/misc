// 199. Binary Tree Right Side View

std::vector<int> rightSideView(TreeNode* root)
{
  std::vector<int> ret;
  std::function<void(TreeNode*, int)> func = [&](TreeNode *node, int k) {
    if (!node) return;
    if (ret.size() < k + 1)
      ret.resize(k + 1);
    ret[k] = node->val;
    func(node->left, k + 1);
    func(node->right, k + 1);
  };
  func(root, 0);
  return ret;
}



// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.



// Example 1:


// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]
