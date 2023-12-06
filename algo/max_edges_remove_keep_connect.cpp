// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable

class DSU {
public:
  DSU(int n) : nodes_(n + 1), edges_(0)
  {
    std::iota(nodes_.begin(), nodes_.end(), 0);
  }

  int find(int x)
  {
    if (nodes_[x] == x) return x;
    return nodes_[x] = find(nodes_[x]);
  }

  int merge(int x, int y)
  {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return 1;
    nodes_[rx] = ry;
    ++edges_;
    return 0;
  }

  int edges() const { return edges_; }

private:
  vector<int> nodes_;
  int edges_;
};

int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
{
  int res = 0;
  DSU A(n);
  for (const auto &e : edges) {
    if (e[0] != 3) continue;
    res += A.merge(e[1], e[2]);
  }

  DSU B(A);
  for (const auto &e : edges) {
    if (e[0] == 3) continue;
    DSU &d = (e[0] == 1) ? A : B;
    res += d.merge(e[1], e[2]);
  }
  return (A.edges() == n - 1 && B.edges() == n - 1) ? res : -1;
}

// Alice and Bob have an undirected graph of n nodes and three types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can be traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.



// Example 1:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// Output: 2
// Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
// Example 2:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// Output: 0
// Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
// Example 3:



// Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// Output: -1
// Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
