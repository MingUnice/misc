// 25. Reverse Nodes in k-Group

ListNode *reverseKGroup(ListNode *head, int k)
{
  int lsize = 0;
  ListNode *p = head;
  while (p) {
    p = p->next;
    lsize++;
  }
  p = head;
  for (int i = k; i <= lsize; i += k) {
    p = reverseBetween(p, i - k + 1, i);
  }
  return p;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
  auto reverse = [](ListNode *l1, ListNode *l2) {
    ListNode *prev = nullptr, *cur = l1, *next;
    do {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    } while (prev != l2);
  };
  ListNode *l_left = head, *l_right = head;
  ListNode *l_left_prev = nullptr, *l_right_next = nullptr;
  for (int i = 0; i < left - 1; ++i) {
    l_left_prev = l_left;
    l_left = l_left->next;
  }
  // printf("l_left %d\n", l_left->val);
  // printf("l_left_prev %d\n", l_left_prev->val);

  for (int i = 0; i < right - 1; ++i)
    l_right = l_right->next;
  l_right_next = l_right->next;

  // printf("l_right %d\n", l_right->val);
  // printf("l_right_next %d\n", l_right_next->val);

  reverse(l_left, l_right);

  // l_right->Print();

  if (l_left_prev)
    l_left_prev->next = l_right;

  l_left->next = l_right_next;

  if (left == 1) return l_right;
  return head;
}


// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
