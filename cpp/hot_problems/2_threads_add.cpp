#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int counter = 0;
const int MAX_COUNT = 20;

void print_num(int thread_id) {
  while(true) {
    std::unique_lock<std::mutex> lock(mtx);

    cv.wait(lock, [&thread_id]
            { return counter % 2 == thread_id || counter > MAX_COUNT; });

    if (counter > MAX_COUNT) {
      if (thread_id == 3) {
        std::cout << "Thread: " << thread_id << "end " << std::endl;
      }
      cv.notify_all();
      break;
    }

    std::cout << "Thread: " << thread_id << "at " << counter << std::endl;
    counter++;
    cv.notify_all();
  }
}

int main() {
  std::thread thread_1(print_num, 1);
  std::thread thread_2(print_num, 0);
  std::thread thread_3(print_num, 3);

  thread_1.join();
  thread_2.join();
  thread_3.join();

  return 0;
}