// #include "54.螺旋矩阵.cpp"
// #include "53.最大子数组和.cpp"
// #include "18.四数之和.cpp"
// #include "322.零钱兑换.cpp"
#include "108.将有序数组转换为二叉搜索树.cpp"
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
  std::vector<int> nums = {-10, -3, 0, 5, 9};

  auto result = sol.sortedArrayToBST(nums);
}