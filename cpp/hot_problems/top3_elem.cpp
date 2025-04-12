#include <iostream>
#include <vector>
#include <climits>

std::vector<int> findTop3(std::vector<int>& input) {
  std::vector<int> result{3, INT_MIN};
  for(auto in: input) {
    if(in > result[2]) {
      result[0] = result[1];
      result[1] = result[2];
      result[2] = in;
    } else if (in > result[1]) {
      result[0] = result[1];
      result[1] = in;
    } else if (in > result[0]) {
      result[0] = in;
    }
  }
  return result;
}