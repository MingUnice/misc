// 105. Construct Binary Tree from Preorder and Inorder Traversal

TreeNode* buildTree(vector<int>& pre, vector<int>& in)
{
  std::map<int, int> pos;
  for (int i = 0; i < in.size(); ++i)
    pos[in[i]] = i;
  std::function<TreeNode *(int, int, int, int)> build =
    [&](int pre_l, int pre_r, int in_l, int in_r) {
      if (pre_l > pre_r)
        return (TreeNode *)nullptr;
      int in_pos = pos[pre[pre_l]];
      int pre_pos = pre_l + (in_pos - in_l);
      auto root = new TreeNode(pre[pre_l]);
      root->left = build(pre_l + 1, pre_pos, in_l, in_pos - 1);
      root->right = build(pre_pos + 1, pre_r, in_pos + 1, in_r);
      return root;
    };
  return build(0, pre.size() - 1, 0, in.size() - 1);
}


// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.



// Example 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
