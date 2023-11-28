#include <thread>
#include <condition_variable>
#include <mutex>

#include <stdio.h>
#include <unistd.h>

int cnt = 1;
std::mutex mtx;
std::condition_variable cv;
int max_cnt = 5;

void print_odd()
{
  while (1) {
    std::unique_lock<std::mutex> lk(mtx);
    if (cnt >= max_cnt) break;
    while (cnt % 2 == 0) {
     cv.wait(lk);
    }
    printf("%d\n", cnt++);
    sleep(1);
    cv.notify_one();
  }
}

void print_even()
{
  while(1) {
    std::unique_lock<std::mutex> lk(mtx);
    if (cnt >= max_cnt) break;
    while (cnt % 2 == 1) {
      cv.wait(lk);
    }
    printf("%d\n", cnt++);
    sleep(1);
    cv.notify_one();
  }
}

int main(int argc, char *argv[])
{
  std::thread thread1(print_odd);
  std::thread thread2(print_even);
  thread1.join();
  thread2.join();
  printf("finished\n");
  
  return 0;
}
