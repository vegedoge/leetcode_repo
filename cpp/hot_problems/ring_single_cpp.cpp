#include <vector>
#include <iostream>
#include <cstring>
#include <stdexcept>

template <typename T>
class RingBuffer {
public:
  // explicit 构造
  explicit RingBuffer(size_t size) :
    buffer_(size),    // buffer_(new T[size]) C语言
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

  size_t pushBatch(const T* source, size_t count) {
    // 先算能不能放下
    size_t freeSpace = capacity_ - (tail_ - head_);
    if (count > freeSpace) {
      count = freeSpace;
    }

    if (count == 0) {
      return 0;
    }

    // 再算需不需要绕回
    size_t tail_wrap = tail_ + count;
    if (tail_wrap < capacity_) {
      memcpy(buffer_.data() + tail_, source, count * sizeof(T));
    } else {
      size_t first_part = capacity_ - tail_;
      size_t second_part = count - first_part;
      memcpy(buffer_.data() + tail_, source, first_part * sizeof(T));
      memcpy(buffer_.data(), source + first_part, second_part * sizeof(T));
    }

    // 处理index
    tail_ = (tail_ + count) % capacity_;
    count_ += count;

    return count;
  }

  size_t popBatch(T* dest, size_t output_count) {
    if (!dest || output_count == 0) {
      return 0;
    }

    // 先算够不够pop
    if (output_count > count_) {
      output_count = count_;
    }

    size_t head_wrap = head_ + output_count;
    if (head_wrap < capacity_) {
      memcpy(dest, buffer_.data() + head_, output_count * sizeof(T));
    } else {
      size_t first_part = capacity_ - head_;
      size_t second_part = output_count - first_part;
      memcpy(dest, buffer_.data() + head_, first_part * sizeof(T));
      memcpy(dest + first_part, buffer_.data(), second_part * sizeof(T));
    }

    head_ = (head_ + output_count) % capacity_;
    count_ -= output_count;

    return output_count;
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
  std::vector<T> buffer_; // T* buffer_  C语言风格
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


  // batch op
  RingBuffer<int> batchRb(10);

  int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int output[10];

  // 写入 12 个，但缓冲区只有 10 容量 → 实际写入 10
  size_t written = batchRb.pushBatch(input, 12);
  std::cout << "Written: " << written << std::endl; // 10

  // 读取 7 个
  size_t read = batchRb.popBatch(output, 7);
  std::cout << "Read: " << read << ", data: ";
  for (size_t i = 0; i < read; ++i) {
      std::cout << output[i] << " ";
  }
  std::cout << std::endl; // 1 2 3 4 5 6 7

  return 0;
}