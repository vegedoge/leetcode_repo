#include <mutex>
#include <iostream>
#include <condition_variable>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
int counter = 1;
const int MAX_COUNT = 100;

void print_number(int thread_id) {
  while (true) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [thread_id]
            { return (counter % 2 == thread_id) || counter > MAX_COUNT; });

    if (counter > MAX_COUNT) {
      cv.notify_one();
      break;
    }

    std::cout << "Thread: " << thread_id << counter << std::endl;

    counter++;
    cv.notify_one();
  }
}

int main() {
  std::thread odd_thread(print_number, 1);
  std::thread even_thread(print_number, 0);

  odd_thread.join();
  even_thread.join();

  std::cout << "Finished" << std::endl;

  return 0;
}
