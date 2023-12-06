// 1847. Closest Room

// sort and set find

vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries)
{
  const size_t n = rooms.size(), m = queries.size();
  std::sort(rooms.begin(), rooms.end(), [](const std::vector<int>&lhs,
                                           const std::vector<int>&rhs) {
    return lhs[1] > rhs[1];
  });
  // record the index before sorting
  for (int i = 0; i < m; ++i) {
    queries[i].push_back(i);
  }
  std::sort(queries.begin(), queries.end(), [](const std::vector<int>&lhs,
                                               const std::vector<int>&rhs) {
    return lhs[1] > rhs[1];
  });

  std::set<int> room_id_set;
  std::vector<int> ret(m);
  int room_idx = 0;
  for (const auto &q : queries) {
    while (room_idx < n && rooms[room_idx][1] >= q[1]) {
      room_id_set.insert(rooms[room_idx][0]);
      room_idx++;
    }
    if (room_id_set.empty()) {
      ret[q[2]] = -1;
      continue;
    }
    int room_id = q[0];
    auto it = room_id_set.lower_bound(room_id);
    if (it == room_id_set.end())
      ret[q[2]] = *std::prev(it);
    else if (it == room_id_set.begin())
      ret[q[2]] = *it;
    else {
      int left = *std::prev(it);
      int right = *it;
      ret[q[2]] = std::abs(room_id - left) <= std::abs(room_id - right) ? left : right;
    }
  }
  return ret;
}

// There is a hotel with n rooms. The rooms are represented by a 2D integer array rooms where rooms[i] = [roomIdi, sizei] denotes that there is a room with room number roomIdi and size equal to sizei. Each roomIdi is guaranteed to be unique.

// You are also given k queries in a 2D array queries where queries[j] = [preferredj, minSizej]. The answer to the jth query is the room number id of a room such that:

// The room has a size of at least minSizej, and
// abs(id - preferredj) is minimized, where abs(x) is the absolute value of x.
// If there is a tie in the absolute difference, then use the room with the smallest such id. If there is no such room, the answer is -1.

// Return an array answer of length k where answer[j] contains the answer to the jth query.



// Example 1:

// Input: rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
// Output: [3,-1,3]
// Explanation: The answers to the queries are as follows:
// Query = [3,1]: Room number 3 is the closest as abs(3 - 3) = 0, and its size of 2 is at least 1. The answer is 3.
// Query = [3,3]: There are no rooms with a size of at least 3, so the answer is -1.
// Query = [5,2]: Room number 3 is the closest as abs(3 - 5) = 2, and its size of 2 is at least 2. The answer is 3.
// Example 2:

// Input: rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
// Output: [2,1,3]
// Explanation: The answers to the queries are as follows:
// Query = [2,3]: Room number 2 is the closest as abs(2 - 2) = 0, and its size of 3 is at least 3. The answer is 2.
// Query = [2,4]: Room numbers 1 and 3 both have sizes of at least 4. The answer is 1 since it is smaller.
// Query = [2,5]: Room number 3 is the only room with a size of at least 5. The answer is 3.
