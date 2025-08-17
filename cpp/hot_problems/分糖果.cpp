/*  公平分糖果 
*   给你一个数组 然后让你分成两块 要求两个集合各自和做差的绝对值最小
*   比如 [1, 2, 3, 4, 5]
*/
// [1, 2, 5][3, 4]
// [1, 2, 4][3, 5]

// dp[i][j]: 用前i个凑出j来

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

int main() {
  // 禁用printf和scanf这种 提高效率
  std::ios_base::sync_with_stdio(false);
  // 接触cin和cout的绑定 cin不会自动flush缓冲区
  std::cin.tie(NULL);

  int n;
  std::cin >> n;

  std::vector<int> nums(n);
  long long total_sum = 0;

  for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
    total_sum += nums[i];
  }

  if (n == 1) {
    std::cout << nums[0] << '\n';
    return 0;
  }

  long long target_sum = total_sum / 2;

  std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target_sum + 1, false));

  // init: 组成0不用任何元素
  for (int i = 0; i < n + 1; ++i) {
    dp[i][0] = true;
  }

  // 其实不用写也行 最前面init过了
  for (int j = 0; j < target_sum + 1; ++j) {
    dp[0][j] = false;
  }

  for (int i = 1; i < n + 1; ++i) {
    for (long long j = 1; j < target_sum + 1; ++j) {
      // 如果不用第i个
      dp[i][j] = dp[i - 1][j];

      // 如果用了第i个，目标值降低
      dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
    }
  } 

  // 找到最接近target：  sum / 2的
  long long first_part_sum = 0;
  for (long long j = target_sum; j >= 0; --j) {
    // 前n个能组成
    if (dp[n][j]) {
      first_part_sum = j;
      break;
    }
  }

  long long second_part_sum = total_sum - first_part_sum;
  long long result = std::abs(first_part_sum - second_part_sum);

  std::cout << result << std::endl;
  return 0;
}
