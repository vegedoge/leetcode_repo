// #include "54.螺旋矩阵.cpp"
#include "53.最大子数组和.cpp"
#include<iostream>

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
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int result = sol.maxSubArray(nums);
}