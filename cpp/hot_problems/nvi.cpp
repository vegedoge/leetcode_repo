#include <iostream>

class Base{
public:
  void print() {
    printImpl(3);
  }

  void print(int n) {
    printImpl(n);
  }

protected:
  int a = 1;
  virtual void printImpl(int n) {
    std::cout << a + n << "\n";
  }
};

class Derived : public Base {
protected:
  int b = 5;
  void printImpl(int n) override {
    std::cout << b + n << "\n";
  }
};

int main() {
  Base *b = new Derived[10];
  b[3].print();
  delete[] b;
}