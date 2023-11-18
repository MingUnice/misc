#ifndef __TRIE_H__
#define __TRIE_H__

#include <unordered_map>

struct TrieNode {
  TrieNode() : is_end_(false) {}
  TrieNode(char key) : key_(key), is_end_(false) {}
  virtual ~TrieNode()
  {
    for (auto it : children_)
      if (it.second)
        delete(it.second);
  }

  char key_;
  bool is_end_;
  std::unordered_map<char, TrieNode *> children_;
};


struct Trie {
  void Insert(std::string s)
  {
    TrieNode *cur = &root_;  
    for (char c : s) {
      if (cur->children_.count(c)) {
        cur = cur->children_.at(c);
      } else {
        TrieNode *node = new TrieNode(c);
        cur->children_[c] = node;
        cur = node;
      }
    }
    cur->is_end_ = true;
  }

  bool Find(std::string s)
  {
    TrieNode *cur = &root_;
    for (char c : s) {
      if (!cur->children_.count(c))
        return false;
      cur = cur->children_.at(c);
    }
    return cur->is_end_;
  }

  bool StartWith(std::string s)
  {
    TrieNode *cur = &root_;
    for (char c : s) {
      if (!cur->children_.count(c))
        return false;
      cur = cur->children_.at(c);
    }
    return true;    
  }
  
  TrieNode root_;
};

#endif
