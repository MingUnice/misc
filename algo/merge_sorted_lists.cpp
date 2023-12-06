// 23. Merge k Sorted Lists
// priority queue

ListNode* mergeKLists(vector<ListNode*>& lists)
{
  if (lists.empty()) return nullptr;
  ListNode dummy(0);
  ListNode *head = &dummy;
  auto compare = [](const ListNode *lhs, const ListNode *rhs) {
    return lhs->val > rhs->val;
  };
  std::priority_queue<ListNode *, std::vector<ListNode*>, decltype(compare)> q(compare);
  for (auto it : lists)
    if (it)
      q.emplace(it);
  while (!q.empty()) {
    ListNode *l = q.top();
    q.pop();
    if (l == nullptr) continue;
    head->next = l;
    head = l;
    if (l->next)
      q.emplace(l->next);
  }
  return dummy.next;
}


// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.



// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []
