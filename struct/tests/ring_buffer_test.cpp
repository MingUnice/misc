#include "ring_buffer.h"

#include <string>

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *reader_function(void *arg)
{
  RingBuffer *q = (RingBuffer *)arg;
  unsigned char *b = (unsigned char *)malloc(3);
  while (1) {
    int len = q->get(b, 3);
    printf("%c %c %c\n", b[0], b[1], b[2]);
    sleep(1);
  }
}

void *writer_function(void *arg)
{
  RingBuffer *q = (RingBuffer *)arg;
  std::string s = "123456789";
  int pos = 0;
  while (1) {
    q->put((unsigned char *)&s[pos], 3);
    pos = (pos + 3) % s.size();
    sleep(1);
  }
}

int main(int argc, char *argv[])
{
  RingBuffer queue(15);
  pthread_t t1, t2;
  pthread_create(&t1, nullptr, reader_function, &queue);
  pthread_create(&t2, nullptr, writer_function, &queue);
  pthread_join(t1, nullptr);
  pthread_join(t2, nullptr);
  return 0;
}
