#include "segment_tree.h"

#include <stdio.h>


int main(int argc, char *argv[])
{
  std::vector<int> nums{9, -8, 1};
  SegmentTree t(nums);
  t.Update(0, 3);
  printf("%d\n", t.SumRange(1, 1));
  printf("%d\n", t.SumRange(0, 1));
  t.Update(1, -3);
  printf("%d\n", t.SumRange(0, 1));
  return 0;
}
