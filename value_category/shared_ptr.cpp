#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

struct A {
  A() { printf("ctor\n"); }
  int d;
};

void f1(std::shared_ptr<A> a)
{
  printf("in func %p %ld\n", &a, a.use_count());
}

void f2(std::shared_ptr<A> &a)
{
  printf("in func %p %ld\n", &a, a.use_count());
}

void f3(std::shared_ptr<A> &&a)
{
  printf("in func %p %ld\n", &a, a.use_count());
}

void f4(const std::shared_ptr<A> &a)
{
  printf("in func %p %ld\n", &a, a.use_count());
}

int main(int argc, char *argv[])
{
  std::shared_ptr<A> a = std::make_shared<A>();
  printf("in main %p %ld\n", &a, a.use_count());
  // f1(a);                        // diff addr, 1 2 1
  // f2(a);                        // same addr, 1 1 1
  // f3(a);                        // cannot build
  // f4(a);                        // same addr, 1 1 1
  // f1(std::move(a));             // diff addr, 1 1 0
  // f2(std::move(a));             // cannot build
  // f3(std::move(a));             // same addr, 1 1 1
  // f4(std::move(a));             // same addr, 1 1 1
  // f1(std::make_shared<A>());    // diff addr, 1 1 1 double ctor
  // f2(std::make_shared<A>());    // cannot build
  // f3(std::make_shared<A>());    // diff addr, 1 1 1 double ctor
  // f4(std::make_shared<A>());    // diff addr, 1 1 1 double ctor
  printf("in main %p %ld\n", &a, a.use_count());
  return 0;
}
