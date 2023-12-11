// 1857. Largest Color Value in a Directed Graph


int largestPathValue(string colors, vector<vector<int>>& edges)
{
  int ret = 0;
  const size_t n = colors.size();
  std::vector<int> in_degree(n);
  std::vector<std::vector<int>> adj_list(n);
  for (const auto &e : edges) {
    int u = e[0];
    int v = e[1];
    adj_list[u].emplace_back(v);
    in_degree[v]++;
  }
  std::queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (in_degree[i] == 0)
      q.push(i);
  }
  std::vector<std::vector<int>> count(n, std::vector<int>(26));
  for (int i = 0; i < n; ++i) {
    count[i][colors[i] - 'a']++;
  }
  int visited = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visited++;
    for (auto v : adj_list[u]) {
      for (int i = 0; i < 26; ++i) {
        int add = colors[v] - 'a' == i ? 1 : 0;
        count[v][i] = std::max(count[v][i], count[u][i] + add);
      }
      if (--in_degree[v] == 0)
        q.push(v);
    }
    ret = std::max(ret, *max_element(count[u].begin(), count[u].end()));
  }
  if (visited != n) return -1;
  return ret;
}


// There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

// You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

// A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

// Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

 

// Example 1:



// Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
// Output: 3
// Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
// Example 2:



// Input: colors = "a", edges = [[0,0]]
// Output: -1
// Explanation: There is a cycle from 0 to 0.
