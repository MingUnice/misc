// 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

class DSU {
public:
  DSU(int n) : nodes_(n + 1), edges_(0)
  {
    iota(nodes_.begin(), nodes_.end(), 0);
  }

  int find (int x)
  {
    if (nodes_[x] == x) return x;
    return nodes_[x] = find(nodes_[x]);
  }

  bool merge(int x, int y)
  {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return false;
    nodes_[rx] = ry;
    ++edges_;
    return true;
  }

  int edges() const { return edges_; }

private:
  vector<int> nodes_;
  int edges_;
};

vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
{
  // n : number of nodes, m : number of edges
  const int m = edges.size();
  // edges : from, to, weight
  vector<vector<int>> q;	// weight, from, to, index
  for (int i = 0; i < m; ++i) {
    q.push_back({edges[i][2], edges[i][0], edges[i][1], i});
  }
  std::sort(q.begin(), q.end());

  auto mst = [&](int ex = -1, int in = -1) -> int {
    DSU dsu(n);
    int cost = 0;
    int count = 0;
    if (in != -1) {
      int w, u, v;
      for (const auto & e : q)
        if (e[3] == in) {
          w = e[0];
          u = e[1];
          v = e[2];
        }
      dsu.merge(u, v);
      cost += w;
      count++;
    }
    for (int i = 0; i < m; ++i) {
      int w = q[i][0], u = q[i][1], v = q[i][2], idx = q[i][3];
      if (idx == ex) continue;
      if (dsu.merge(u, v)) {
        cost += w;
        count++;
      }
    }
    // printf("%d %d %d %d\n", ex, in, count, cost);
    return count == n - 1 ? cost : INT_MAX;
  };

  int min_mst = mst();
  vector<int> c, p;
  for (int i = 0; i < m; ++i) {
    if (mst(i) > min_mst) {
      c.push_back(i);
    } else if (mst(-1, i) == min_mst) {
      p.push_back(i);
    }
  }

  return {c, p};
}



// Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

// Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

// Note that you can return the indices of the edges in any order.

// Example 1:

// Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
// Output: [[0,1],[2,3,4,5]]
