// 752. Open the Lock

int openLock(vector<string>& deadends, string target) {
  const string start = "0000";
  unordered_set<string> dead(deadends.begin(), deadends.end());
  if (dead.count(start)) return -1;
  if (start == target) return 0;

  queue<string> q;
  unordered_set<string> visited{start};

  int steps = 0;
  q.push(start);
  while (!q.empty()) {
    ++steps;
    const int size = q.size();
    for (int i = 0; i < size; ++i) {
      const string curr = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i)
        for (int j = -1; j <= 1; j += 2) {
          string next = curr;
          next[i] = (next[i] - '0' + j + 10) % 10 + '0';
          if (next == target) return steps;
          if (dead.count(next) || visited.count(next)) continue;
          q.push(next);
          visited.insert(next);
        }
    }
  }

  return -1;
}

int openLock(vector<string>& deadends, string target) {
  const string start = "0000";
  unordered_set<string> dead(deadends.begin(), deadends.end());
  if (dead.count(start)) return -1;
  if (target == start) return 0;

  queue<string> q1;
  queue<string> q2;
  unordered_set<string> v1{start};
  unordered_set<string> v2{target};

  int s1 = 0;
  int s2 = 0;
  q1.push(start);
  q2.push(target);
  while (!q1.empty() && !q2.empty()) {
    if (!q1.empty()) ++s1;
    const int size = q1.size();
    for (int i = 0; i < size; ++i) {
      const string curr = q1.front();
      q1.pop();
      for (int i = 0; i < 4; ++i)
        for (int j = -1; j <= 1; j += 2) {
          string next = curr;
          next[i] = (next[i] - '0' + j + 10) % 10 + '0';
          if (v2.count(next)) return s1 + s2;
          if (dead.count(next) || v1.count(next)) continue;
          q1.push(next);
          v1.insert(next);
        }
    }
    swap(q1, q2);
    swap(v1, v2);
    swap(s1, s2);
  }

  return -1;
}

int openLock(vector<string>& deadends, string target) {
  constexpr int kMaxN = 10000;
  const vector<int> bases{1, 10, 100, 1000};
  const int start = 0;
  const int goal = stoi(target);

  queue<int> q1;
  queue<int> q2;
  vector<int> v1(kMaxN, 0);
  vector<int> v2(kMaxN, 0);
  for (const string& deadend : deadends)
    v1[stoi(deadend)] = v2[stoi(deadend)] = -1;

  if (v1[start] == -1) return -1;
  if (start == goal) return 0;

  v1[start] = 1;
  v2[goal] = 1;

  int s1 = 0;
  int s2 = 0;
  q1.push(start);
  q2.push(goal);
  while (!q1.empty() && !q2.empty()) {
    if (!q1.empty()) ++s1;
    const int size = q1.size();
    for (int i = 0; i < size; ++i) {
      const int curr = q1.front();
      q1.pop();
      for (int i = 0; i < 4; ++i) {
        int r = (curr / bases[i]) % 10;
        for (int j = -1; j <= 1; j += 2) {
          const int next = curr + ((r + j + 10) % 10 - r) * bases[i];
          if (v2[next] == 1) return s1 + s2;
          if (v1[next]) continue;
          q1.push(next);
          v1[next] = 1;
        }
      }
    }
    swap(q1, q2);
    swap(v1, v2);
    swap(s1, s2);
  }
  return -1;
}

// You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

// The lock initially starts at '0000', a string representing the state of the 4 wheels.

// You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

// Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.



// Example 1:

// Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// Output: 6
// Explanation:
// A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
// Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
// because the wheels of the lock become stuck after the display becomes the dead end "0102".
// Example 2:

// Input: deadends = ["8888"], target = "0009"
// Output: 1
// Explanation: We can turn the last wheel in reverse to move from "0000" -> "0009".
// Example 3:

// Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
// Output: -1
// Explanation: We cannot reach the target without getting stuck.


// Constraints:

// 1 <= deadends.length <= 500
// deadends[i].length == 4
// target.length == 4
// target will not be in the list deadends.
// target and deadends[i] consist of digits only.
