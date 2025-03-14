#include <iostream>
#include <vector>
using namespace std;

bool is_valid_sequence(const vector<int>& sequence) {
    int sum = 0;
    for (int i = 0; i < sequence.size(); ++i) {
        sum += (sequence[i] * (i + 1));
    }
    return sum % 3 == 0;
}

void generate_and_print_sequence(int n) {
    vector<int> sequence(n);
    // Initialize the sequence in increasing order
    for (int i = 0; i < n; ++i) {
        sequence[i] = i + 1;
    }

    if (is_valid_sequence(sequence)) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        // If the initial sequence does not satisfy the condition,
        // we try to find a valid one by swapping elements.
        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = i + 1; j < n && !found; ++j) {
                swap(sequence[i], sequence[j]);
                if (is_valid_sequence(sequence)) {
                    found = true;
                } else {
                    // Swap back if the sequence is still not valid
                    swap(sequence[i], sequence[j]);
                }
            }
        }
        if (found) {
            for (int num : sequence) {
                cout << num << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        generate_and_print_sequence(n);
    }
    return 0;
}
// #include <iostream>
// #include <vector>
// using namespace std;

// int bit_mul(vector<int> arr1, vector<int> arr2) {
//     int result = 0;
//     for (int i = 0; i < arr1.size(); i++) {
//         result += arr1[i] * arr2[i] + 1;
//     }
//     return result;
// }

// int main() {
//     int t;
//     cin >> t;
//     vector<int> input_size(t);
//     vector<int> vanilla;
//     vector<int> mirror;
//     vector<vector<int>> results;
//     vector<int> flags;
//     int temp;
//     int sigma;
//     for (int i = 0; i < t; i++) {
//         int n;
//         cin >> n;
//         input_size[i] = n;
//         flags.push_back(-1);
//         // initialize an increasing array
//         for (int j = 0; j < n; j++) {
//             vanilla.push_back(j);
//         }
//         mirror = vanilla;
    
//         for (int last = mirror.size() - 1; last > 0; last--) {
//             for (int first = 0; first < last; first ++) {
//                 temp = mirror[first + 1];
//                 mirror[first+1] = mirror[first];
//                 mirror[first] = temp;
//             }
//             sigma = bit_mul(mirror, vanilla);
//             if (sigma % 3 == 0) {
//                 results.push_back(mirror);
//                 flags[i] = 1;
//                 break;
//             }
//             results.push_back({-1});
//         }
//     }

//     for (int k = 0; k < t; k++) {
//       for (int l = 0; l < input_size[k]; l++) {
//         cout << results[k][l] << " ";
//       }
//       cout << endl;
//     }

// }
