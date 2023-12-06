// 86. Partition List

ListNode* partition(ListNode* head, int k)
{
  if (!head) return head;
  ListNode dummy1(0), dummy2(0);
  ListNode *l1 = &dummy1, *l2 = &dummy2;
  ListNode *p = head;
  while (p) {
    if (p->val < k) {
      l1 = l1->next = p;
    } else {
      l2 = l2->next = p;
    }
    p = p->next;
  }
  l1->next = dummy2.next;
  l2->next = nullptr;
  return dummy1.next;
}


// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.



// Example 1:


// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]
// Example 2:

// Input: head = [2,1], x = 2
// Output: [1,2]
