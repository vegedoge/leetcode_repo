#include <cstddef>
#include <iostream>

template <typename T>
class SharedPtr{
public:
  explicit SharedPtr(T* ptr = nullptr) :
    ptr_(ptr), ref_count_(ptr ? new long(1) : nullptr) {}

  // copy
  SharedPtr(const SharedPtr& other) :
    ptr_(other.ptr_), ref_count_(other.ref_count_) {
      if (ref_count_) {
        ++(*ref_count_);
      }
    }

  // copy assign
  SharedPtr& operator=(const SharedPtr& other) {
    if (this != &other) {
      release();

      ptr_ = other.ptr_;
      ref_count_ = other.ref_count_;
      if (ref_count_) {
        ++(*ref_count_);
      }
    }
    return *this;
  }

  ~SharedPtr() {
    release();
  }

  // 解引用
  T &operator*() const { return *ptr_; }
  T *operator->() const { return ptr_; }

  T *get() const { return ptr_; }

  long use_count() const {
    return ref_count_ ? *ref_count_ : 0;
  }

  // if check
  explicit operator bool() const {
    return ptr_ != nullptr;
  }

private:
  T *ptr_;            //指向目标对象
  long *ref_count_;   //指向rc

  // 释放
  void release() {
    if (ptr_ && ref_count_) {
      if (--(*ref_count_) == 0) {
        delete ptr_;
        delete ref_count_;
      }
    }

    ptr_ = nullptr;
    ref_count_ = nullptr;
  }
};

int main() {
    SharedPtr<int> p1(new int(42));
    std::cout << "*p1 = " << *p1 << ", use_count = " << p1.use_count() << std::endl; // 1

    {
        SharedPtr<int> p2 = p1;
        std::cout << "After copy: use_count = " << p1.use_count() << std::endl; // 2
    } // p2 析构，计数变 1

    std::cout << "After p2 out of scope: use_count = " << p1.use_count() << std::endl; // 1

    SharedPtr<int> p3;
    p3 = p1; // 赋值
    std::cout << "After assign: use_count = " << p1.use_count() << std::endl; // 2

    return 0;
}