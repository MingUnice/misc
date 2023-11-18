#include "trie.h"

int main(int argc, char *argv[])
{
  Trie trie;
  trie.Insert("abcd");
  trie.Insert("bbbasda");
  printf("%d\n", trie.Find("abcd"));  
  printf("%d\n", trie.Find("abc"));
  printf("%d\n", trie.StartWith("abc"));
  return 0;
}
