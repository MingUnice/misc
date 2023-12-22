// 212. Word Search II

struct TrieNode {
  TrieNode() : nodes(26) {}
  ~TrieNode()
  {
    for (auto n : nodes)
      if (n) delete(n);
  }

  std::string word;
  std::vector<TrieNode *> nodes;
};

vector<string> findWords(vector<vector<char>>& nums, vector<string>& words)
{
  TrieNode root;
  for (const auto &s : words) {
    TrieNode *cur = &root;
    for (char c : s) {
      TrieNode *&next = cur->nodes[c - 'a'];
      if (!next)
        next = new TrieNode();
      cur = next;
    }
    cur->word = s;
  }
  const size_t m = nums.size(), n = nums[0].size();
  std::vector<std::string> ret;
  std::function<void(int, int, TrieNode*)> dfs = [&](int x, int y, TrieNode *node) {
    if (x < 0 || x >= m || y < 0 || y >= n || nums[x][y] == 0)
      return;
    char c = nums[x][y];
    TrieNode *next = node->nodes[c - 'a'];
    if (!next) return;
    if (next->word.size()) {
      ret.push_back(next->word);
      next->word.clear();
    }
    nums[x][y] = 0;
    dfs(x - 1, y, next);
    dfs(x + 1, y, next);
    dfs(x, y - 1, next);
    dfs(x, y + 1, next);
    nums[x][y] = c;
  };
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      dfs(i, j, &root);
    }
  }
  return ret;
}


// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



// Example 1:


// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:


// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []


// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.
