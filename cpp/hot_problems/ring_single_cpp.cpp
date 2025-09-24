#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T>
class RingBuffer {
public:
  // explicit 构造
  explicit RingBuffer(size_t size) :
    buffer_(size),
    head_(0),
    tail_(0),
    count_(0),
    capacity_(size) {
      if (size == 0) {
        throw std::invalid_argument("RingBuffer size must > 0");
      }
    }

  void push(const T& value) {
    if (isFull()) {
      throw std::runtime_error("RingBuffer is full");
    }
    buffer_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    ++count_;
  }

  T pop() {
    if (isEmpty()) {
      throw std::runtime_error("RingBuffer is empty");
    }
    T value = buffer_[head_];
    head_ = (head_ + 1) % capacity_;
    --count_;
    return value;
  }

  bool isEmpty() const {
    return count_ == 0;
  }

  bool isFull() const {
    return count_ == capacity_;
  }

  size_t size() const {
    return count_;
  }

  T front() const {
    if (isEmpty()) {
      throw std::runtime_error("Ringbuffer is empty");
    }
    return buffer_[head_];
  }

private: 
  std::vector<T> buffer_;
  size_t head_;
  size_t tail_;
  size_t count_;
  size_t capacity_;
};

int main() {
  RingBuffer<int> rb(3);

  std::cout << "Is Empty? " << rb.isEmpty() << std::endl;

  rb.push(10);
  rb.push(20);
  rb.push(30);

  std::cout << "Is full? " << rb.isFull() << std::endl;    // 1 (true)
  std::cout << "Size: " << rb.size() << std::endl;         // 3

  // 再 push 会抛异常
  // rb.push(40);  // ❌ runtime_error

  std::cout << rb.pop() << std::endl;  // 10
  std::cout << rb.pop() << std::endl;  // 20
  std::cout << rb.pop() << std::endl;

  rb.push(40);  // 现在可以 push 了
  std::cout << "Front: " << rb.front() << std::endl;  // 30

  return 0;
}