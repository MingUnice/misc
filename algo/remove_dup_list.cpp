// 82. Remove Duplicates from Sorted List II


ListNode* deleteDuplicates(ListNode* head)
{
  if (!head) return head;
  ListNode *prev = nullptr, *cur = head, *next;
  int val;
  bool is_dup = false;
  while (cur && cur->next) {
    val = cur->val;
    while (cur->next && cur->next->val == val) {
      cur = cur->next;
      is_dup = true;
    }
    if (is_dup) {
      if (prev) {
        prev->next = cur->next;
      } else {
        head = cur->next;
      }
      is_dup = false;
    } else {
      prev = cur;
    }
    cur = cur->next;
  }
  return head;
}

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.



// Example 1:


// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:


// Input: head = [1,1,1,2,3]
// Output: [2,3]
