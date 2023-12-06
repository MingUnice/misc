// 211. Design Add and Search Words Data Structure

struct TrieNode {
  TrieNode(char key) : key_(key) {}
  TrieNode() {}

  bool is_end_ = false;
  char key_;
  std::unordered_map<char, TrieNode*> child_;
};

class WordDictionary {
public:
  WordDictionary() {}

  void addWord(string word) {
    TrieNode *cur = &root;
    for (auto c : word) {
      if (cur->child_.count(c) == 0) {
        TrieNode *node = new TrieNode(c);
        cur->child_[c] = node;
      }
      cur = cur->child_[c];
    }
    cur->is_end_ = true;
  }

  bool search(string word)
  {
    const size_t n = word.size();
    std::function<bool(int, TrieNode*)> f = [&](int l, TrieNode* node) {
      if (l == n) return node->is_end_;
      char c = word[l];
      if (c == '.') {
        for (auto it : node->child_)
          if (f(l + 1, it.second)) return true;
        return false;
      } else {
        if (node->child_.count(c) == 0)
          return false;
        return f(l + 1, node->child_[c]);
      }
      return true;
    };
    return f(0, &root);
  }

  void print()
  {
    std::function<void(TrieNode*)> f = [&](TrieNode *n) {
      printf("(%c | %d) ", n->key_, n->is_end_);
      for (auto it : n->child_)
        f(it.second);
    };
    f(&root);
  }

  TrieNode root;
};


// Design a data structure that supports adding new words and finding if a string matches any previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.


// Example:

// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True
