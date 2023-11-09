#ifndef __RBTREE_H__
#define __RBTREE_H__

#include "utils.h"

struct rb_node {
  unsigned long rb_parent_color;
  struct rb_node *rb_right;
  struct rb_node *rb_left;
};

struct rb_root {
  struct rb_node *rb_node;
};

struct rb_root_cached {
  struct rb_root rb_root;
  struct rb_node *rb_mostleft;
};

#define rb_entry(ptr, type, member) container_of(ptr, type, member)

#define rb_parent(r) ((struct rb_node *)((r)->rb_parent_color & ~3))

#endif
