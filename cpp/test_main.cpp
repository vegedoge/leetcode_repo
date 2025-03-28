// #include "54.螺旋矩阵.cpp"
// #include "53.最大子数组和.cpp"
// #include "18.四数之和.cpp"
#include "322.零钱兑换.cpp"
#include<iostream>
using namespace std;

int main() {
  Solution sol;
  //54
  // vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  // vector<int> result = sol.spiralOrder(matrix);
  // for (auto it : result)
  // {
  //   std::cout << it << ",";
  // }
  // std::cout << endl;
  
  // 53
  std::vector<int> nums = {1, 2, 5};
  int target = 9;
  auto result = sol.coinChange(nums, target);
  printf("output: %d \n", result);
}