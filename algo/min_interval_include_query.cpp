// 1851. Minimum Interval to Include Each Query

// sort and priority queue

vector<int> minInterval(vector<vector<int>>& vals, vector<int>& q)
{
  const size_t n = vals.size(), m = q.size();
  std::vector<int> ret(m);
  std::vector<std::pair<int, int>> qs;
  for (int i = 0; i < m; ++i) {
    qs.push_back({q[i], i});
  }
  std::sort(qs.rbegin(), qs.rend());
  std::sort(vals.begin(), vals.end(), [](const std::vector<int> &lhs,
                                         const std::vector<int> &rhs) {
    return lhs[1] > rhs[1];
  });


  auto compare = [](const std::pair<int, int> &lhs,
                    const std::pair<int, int> &rhs) {
    return lhs.first > rhs.first;
  };

  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      decltype(compare)> pq(compare);
  int idx = 0;
  for (int i = 0; i < m; ++i) {
    int k = qs[i].first;
    int v = qs[i].second;
    while (idx < n && vals[idx][1] >= k) {
      pq.push({vals[idx][1] - vals[idx][0], vals[idx][0]});
      idx++;
    }
    while (!pq.empty() && pq.top().second > k) {
      pq.pop();
    }
    if (pq.empty()) {
      ret[v] = -1;
      continue;
    }
    ret[v] = pq.top().first + 1;
  }
  return ret;
}


// You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.

// You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.

// Return an array containing the answers to the queries.



// Example 1:

// Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
// Output: [3,3,1,4]
// Explanation: The queries are processed as follows:
// - Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
// - Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
// - Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
// - Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
// Example 2:

// Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
// Output: [2,-1,4,6]
// Explanation: The queries are processed as follows:
// - Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
// - Query = 19: None of the intervals contain 19. The answer is -1.
// - Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
// - Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.
