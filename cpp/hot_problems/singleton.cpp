#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

class Singleton {
private:
  Singleton() {
    std::cout << "Singleton constructed" << '\n';
  }

  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton) = delete;

private:
  static std::mutex cout_mtx;

public:
  // 线程安全的get
  static Singleton& getInstance() {
    static int counter = 0;
    counter++;
    {
      std::unique_lock<std::mutex> lock(cout_mtx);
      printf("call count: %d\n", counter);
    }

    static Singleton instance;
    return instance;
  }

  void func() {
    std::unique_lock<std::mutex> lock(cout_mtx);
    printf("functions inside Singleton called\n");
  }
};

void test() {
  Singleton& s = Singleton::getInstance();
  s.func();
}

std::mutex Singleton::cout_mtx;

int main() {
  std::vector<std::thread> threads;
  for (int i = 0; i < 4; ++i) {
    threads.emplace_back(test);
  }

  for (auto& t: threads) {
    t.join();
  }

  return 0;
}
