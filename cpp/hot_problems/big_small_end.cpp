// 查看机器的大小端

#include <iostream>

// 用union共享内存也可以
bool is_little_endian() {
  union {
    int i;
    char c;
  } u = {1};

  // 如果小端 : 01 00 00 00
  //     大端:  00 00 00 01
  return u.c == 1;
}

int main() {
  int x;
  int *p = &x;
  *p = 0x12345678;

  char *cp = reinterpret_cast<char *>(p);

  std::cout << "Bytes: ";
  for (int i = 0; i < sizeof(int); ++i) {
    printf("%02X", cp[i] & 0xFF);
  }
  std::cout << std::endl;

  if (*cp == 0x78) {
    std::cout << "small endian" << std::endl;
  } else {
    printf("Big endian\n");
  }

  std::cout << "small endian with union: " << is_little_endian() << std::endl;

  return 0;
}