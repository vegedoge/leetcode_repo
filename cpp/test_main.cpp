#include "54.螺旋矩阵.cpp"
#include<iostream>

int main() {
  Solution sol;
  vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<int> result = sol.spiralOrder(matrix);
  for(auto it: result) {
    std::cout << it << ",";
  }
  std::cout << endl;
}