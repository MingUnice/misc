// 1114. Print in Order

// cv 22ms
class Foo {
public:
  Foo() {
  }

  void first(std::function<void()> printFirst) {
    std::unique_lock<std::mutex> lk(mtx);
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    count = 1;
    cv.notify_all();
  }

  void second(std::function<void()> printSecond) {
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk, [&](){ return count == 1; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    count = 2;
    cv.notify_all();
  }

  void third(std::function<void()> printThird) {
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk, [&](){ return count == 2; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
private:
  std::mutex mtx;
  std::condition_variable cv;
  int count = 0;

};

// semaphore 120ms
class Foo {
public:
  Foo() {
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 1);
    sem_wait(&s1);
    sem_wait(&s2);

  }

  void first(function<void()> printFirst) {

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    sem_post(&s1);
  }

  void second(function<void()> printSecond) {
    sem_wait(&s1);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    sem_post(&s2);
  }

  void third(function<void()> printThird) {
    sem_wait(&s2);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
private:
  sem_t s1, s2;

};


// mutex 176ms
class Foo {
public:
  Foo() {
    mutex1_.lock();
    mutex2_.lock();
  }

  void first(function<void()> printFirst) {

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    mutex1_.unlock();
  }

  void second(function<void()> printSecond) {
    mutex1_.lock();
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    mutex2_.unlock();
  }

  void third(function<void()> printThird) {
    mutex2_.lock();
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
private:
  mutex mutex1_, mutex2_;

};

// Suppose we have a class:

// public class Foo {
//   public void first() { print("first"); }
//   public void second() { print("second"); }
//   public void third() { print("third"); }
// }
// The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

// Note:

// We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.



// Example 1:

// Input: nums = [1,2,3]
// Output: "firstsecondthird"
// Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
// Example 2:

// Input: nums = [1,3,2]
// Output: "firstsecondthird"
// Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
