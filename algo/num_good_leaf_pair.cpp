// 1530. Number of Good Leaf Nodes Pairs

int countPairs(TreeNode *root, int distance)
{
  // child -> parent
  unordered_map<TreeNode *, TreeNode *> parents;
  vector<TreeNode *> leaves;
  std::function<void(TreeNode *, TreeNode *)> dfs =
    [&](TreeNode *c, TreeNode *p) {
      if (!c) return;
      parents[c] = p;
      dfs(c->left, c);
      dfs(c->right, c);
      if (!c->left && !c->right) leaves.push_back(c);
    };

  dfs(root, nullptr);
  // parent -> distance
  unordered_map<TreeNode *, int> a;
  auto isGood = [&](TreeNode *n) -> int {
    for (int i = 0; i < distance && n; ++i, n = parents[n])
      if (a.count(n) && a[n] + i <= distance) return 1;
    return 0;
  };
  int res = 0;
  for (int i = 0; i < leaves.size(); ++i) {
    TreeNode *n1 = leaves[i];
    a.clear();
    for (int k = 0; k < distance && n1; ++k, n1 = parents[n1])
      a[n1] = k;
    for (int j = i + 1; j < leaves.size(); ++j)
      res += isGood(leaves[j]);
  }

  return res;
}

// You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

// Return the number of good leaf node pairs in the tree.



// Example 1:


// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
// Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
// Example 2:


// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
