// 207. Course Schedule


bool canFinish(int n, std::vector<std::vector<int>> &g)
{
  std::vector<std::vector<int>> r(n);
  std::vector<int> status(n, 0);
  for (auto it : g) {
    r[it[1]].push_back(it[0]);
  }
  std::function<bool(int)> dfs = [&](int k) {
    if (status[k] == 2) return false;
    status[k] = 1;
    for (auto it : r[k]) {
      if (status[it] == 1) return true;
      if (dfs(it)) return true;
    }
    status[k] = 2;
    return false;
  };
  for (int i = 0; i < n; ++i) {
    if (dfs(i)) return false;
  }
  return true;
}

// topological sort
bool canFinish(int n, std::vector<std::vector<int>> &g)
{
  int visited = 0;
  std::vector<std::vector<int>> adj_list(n);
  std::vector<int> in_degree(n);
  for (const auto &e : g) {
    int u = e[0];
    int v = e[1];
    adj_list[u].push_back(v);
    in_degree[v]++;
  }
  std::queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (in_degree[i] == 0)
      q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visited++;
    for (auto v : adj_list[u]) {
      if (--in_degree[v] == 0)
        q.push(v);
    }
  }
  return visited == n;
}


// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.



// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
