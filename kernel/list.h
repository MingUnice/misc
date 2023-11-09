#ifndef __LIST_H__
#define __LIST_H__

#include "utils.h"

#define list_entry(ptr, type, member) container_of(ptr, type, member)

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define list_for_each(pos, head) \
  for (pos = (head)->next; __builtin_prefetch(pos->next), pos != (head); pos = pos->next)

#define list_for_each_entry(pos, head, member)                          \
  for (pos = list_entry((head)->next, typeof(*pos), member);            \
       &pos->member != (head);                                          \
       pos = list_entry(pos->member.next, typeof(*pos), member))

struct list_head {
  struct list_head *next;
  struct list_head *prev;
};

template<class T>
struct ListNode {
  T value;
  struct list_head list = LIST_HEAD_INIT(list);
};

#endif
