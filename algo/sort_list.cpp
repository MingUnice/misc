// 148. Sort List

ListNode* sortList(ListNode* head)
{
  if (!head) return nullptr;
  ListNode dummy(0);
  ListNode *l = head;
  auto compare = [](const ListNode *lhs, const ListNode *rhs) {
    return lhs->val > rhs->val;
  };
  std::priority_queue<ListNode *,
                      std::vector<ListNode *>,
                      decltype(compare)> q(compare);
  while (l) {
    q.emplace(l);
    l = l->next;
  }
  dummy.next = q.top();
  l = dummy.next;
  q.pop();
  while (!q.empty() && l) {
    ListNode *tmp = q.top();
    q.pop();
    l->next = tmp;
    l = tmp;
  }
  l->next = nullptr;
  return dummy.next;
}


// Given the head of a linked list, return the list after sorting it in ascending order.

// Example 1:


// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:


// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
