#include <set>
#include <stdio.h>

struct Item {
  Item() {}
  Item(int _id, int _val) : id(_id), val(_val) {}

  bool operator<(const Item &other) {
    return this->val < other.val;
  }
  friend bool operator<(const Item &lhs, const Item &rhs) {
    return lhs.val < rhs.val;
  }

  int id;
  int val;
};

std::multiset<Item> item_list;

void test1(int id, int cnt)
{
  for (auto it = item_list.begin();
       it != item_list.end();) {
    if (it->id == id) {
      it = item_list.erase(it);
      if (--cnt == 0)
        break;
    } else {
      ++it;
    }
  }
}

void test2(int id, int cnt)
{
  for (auto it = item_list.rbegin();
       it != item_list.rend();) {
    if (it->id == id) {
      it = (decltype(it))item_list.erase(std::next(it).base());
      if (--cnt == 0)
        break;
    } else {
      ++it;
    }
  }
}

int main(int argc, char *argv[])
{
  item_list.insert(Item(1, 3));
  item_list.insert(Item(2, 3));
  item_list.insert(Item(1, 10));
  item_list.insert(Item(4, 7));
  item_list.insert(Item(5, 11));
  item_list.insert(Item(1, 10));
  item_list.insert(Item(5, 2));

  for (auto it : item_list)
    printf("(%d %d) ", it.id, it.val);
  printf("\n");

  test1(1, 2);

  for (auto it : item_list)
    printf("(%d %d) ", it.id, it.val);
  printf("\n");

  return 0;
}
