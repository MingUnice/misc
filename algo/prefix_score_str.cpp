// 2416. Sum of Prefix Scores of Strings

struct TrieNode {
  TrieNode() {}
  TrieNode(char key) : key_(key), cnt_(0) {}

  void Insert(std::string s)
  {

  }

  char key_;
  int cnt_;
  std::unordered_map<char, TrieNode*> children_;
};

struct Trie {
  Trie() {}
  void Insert(std::string s)
  {
    TrieNode *node = &root_;
    for (char c : s) {
      if (node->children_.count(c)) {
        node = node->children_.at(c);
      } else {
        auto new_node = new TrieNode(c);
        node->children_[c] = new_node;
        node = new_node;
      }
      node->cnt_++;
    }
  }

  int Find(std::string s)
  {
    TrieNode *node = &root_;
    int ret = 0;
    for (char c : s) {
      if (node->children_.count(c) == 0)
        return -1;
      node = node->children_[c];
      ret += node->cnt_;
    }
    return ret;
  }
  TrieNode root_;
};

vector<int> sumPrefixScores(vector<string>& strs)
{
  Trie trie;
  std::vector<int> ret;
  for (std::string s : strs)
    trie.Insert(s);
  for (std::string s : strs)
    ret.push_back(trie.Find(s));
  return ret;
}

// You are given an array words of size n consisting of non-empty strings.

// We define the score of a string word as the number of strings words[i] such that word is a prefix of words[i].

// For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
// Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

// Note that a string is considered as a prefix of itself.

 

// Example 1:

// Input: words = ["abc","ab","bc","b"]
// Output: [5,4,3,2]
// Explanation: The answer for each string is the following:
// - "abc" has 3 prefixes: "a", "ab", and "abc".
// - There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
// The total is answer[0] = 2 + 2 + 1 = 5.
// - "ab" has 2 prefixes: "a" and "ab".
// - There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
// The total is answer[1] = 2 + 2 = 4.
// - "bc" has 2 prefixes: "b" and "bc".
// - There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
// The total is answer[2] = 2 + 1 = 3.
// - "b" has 1 prefix: "b".
// - There are 2 strings with the prefix "b".
// The total is answer[3] = 2.
// Example 2:

// Input: words = ["abcd"]
// Output: [4]
// Explanation:
// "abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
// Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.
