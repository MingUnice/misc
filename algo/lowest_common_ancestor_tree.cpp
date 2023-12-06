// 236. Lowest Common Ancestor of a Binary Tree


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2)
{
  TreeNode *ret = nullptr;
  std::function<std::pair<bool, bool>(TreeNode *)> helper =
    [&](TreeNode *node) -> std::pair<bool, bool> {
    if (!node || ret) return {false, false};
    bool b1 = false, b2 = false;
    if (node == n1) b1 = true;
    if (node == n2) b2 = true;
    auto lb = helper(node->left);
    auto rb = helper(node->right);
    if (lb.first || rb.first) b1 = true;
    if (lb.second || rb.second) b2 = true;
    if (b1 && b2 && !ret) ret = node;
    return {b1, b2};
  };
  helper(root);
  return ret;
}



// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”



// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
