#include "kmp.h"

int main(int argc, char *argv[])
{
  auto ret = Match("ABC ABCDAB ABCDABCDABDE", "AB");
  for (auto i : ret)
    printf("%d ", i);
  printf("\n");
  return 0;
}
