// 839. Similar String Groups

struct DSU {

  DSU() {}
  DSU(size_t size) : size_(size), edge_(0), parent_(size), rank_(size)
  {
    std::iota(parent_.begin(), parent_.end(), 0);
  }
  virtual ~DSU() {}

  int Find(int n)
  {
    if (parent_[n] == n) return n;
    return parent_[n] = Find(parent_[n]);
  }

  bool Merge(int l, int r)
  {
    int lp = Find(l);
    int rp = Find(r);
    if (lp == rp) return false;
    if (rank_[rp] > rank_[lp])
      std::swap(lp, rp);
    parent_[lp] = rp;
    if (rank_[lp] == rank_[rp])
      ++rank_[lp];
    ++edge_;
    return true;
  }

  size_t size_;
  size_t edge_;
  std::vector<int> parent_;
  std::vector<int> rank_;
};


  int numSimilarGroups(vector<string>& strs)
  {
    const size_t n = strs.size();
    auto str_similar = [](const std::string &lhs,
                           const std::string &rhs) -> bool {
      const size_t nstr = lhs.size();
      int diff = 0;
      for (int i = 0; i < nstr; ++i) {
        if (lhs[i] != rhs[i]) diff++;
        if (diff > 2) return false;
      }
      return true;
    };
    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (str_similar(strs[i], strs[j]))
          dsu.Merge(i, j);
      }
    }
    return n - dsu.edge_;
  }



// Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.

// For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

// Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

// We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?



// Example 1:

// Input: strs = ["tars","rats","arts","star"]
// Output: 2
// Example 2:

// Input: strs = ["omv","ovm"]
// Output: 1
