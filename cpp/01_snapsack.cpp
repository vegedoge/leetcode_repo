#include <iostream>
#include <vector>
using namespace std;

// int main() {
//   int n, bag_size;

//   cin >> n >> bag_size;

//   vector<int> weights(n, 0);
//   vector<int> values(n, 0);

//   for (int i = 0; i < n; i++) {
//     cin >> weights[i];
//   }

//   for (int i = 0; i < n; i++) {
//     cin >> values[i];
//   }

//   // get all zeros
//   vector<vector<int>> dp(weights.size(), vector<int>(bag_size + 1, 0));

//   // assign values to the first row
//   for (int i = weights[0]; i <= bag_size; i++) {
//     dp[0][i] = values[0];
//   }

//   for (int i = 1; i < weights.size(); i++) {
//     for (int j = 1; j < bag_size + 1; j++) {
//       if (j < weights[i]) {
//         dp[i][j] = dp[i - 1][j];
//       } else {
//         dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
//       }
//     }
//   }
//   cout << dp[n - 1][bag_size] << endl;
//   return 0;
// }


// one dimension dp

int main() {
  int M, N;
  cin >> M >> N;

  vector<int> costs(M);
  vector<int> values(M);

  for (int i = 0; i < M; i++) {
    cin >> costs[i];
  }
  for (int j = 0; j < M; j++) {
    cin >> values[j];
  }

  vector<int> dp(N + 1, 0);

  for (int i = 0; i < M; i++) {
    for (int j = N; j >= costs[i]; j--) {
      dp[j] = max(dp[j], dp[j - costs[i]] + values[i]);
    }
  }

  cout <<dp[N] << endl;
  return 0;
}