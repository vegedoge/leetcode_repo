#include <vector>
#include <iostream>

int partition(std::vector<int>& arr, int left, int right) {
  int pivot = arr[right];
  int cursor = left;

  for (int i = left; i < right; i++) {
    if (arr[i] <= pivot) {
      std::swap(arr[cursor], arr[i]);
      cursor++;
    }
  }
  // move pivot to the right position
  std::swap(arr[cursor], arr[right]);

  return cursor;
}

void quick_sort(std::vector<int>& arr, int left, int right) {
  if (left < right) {
    int pivot = partition(arr, left, right);
    quick_sort(arr, left, pivot - 1);
    quick_sort(arr, pivot + 1, right);
  }
}

int main() {
  std::vector<int> test_arr{4, 11, 3, 0 - 2, 5, 100, -4, 1};
  quick_sort(test_arr, 0, test_arr.size() - 1);
  for (auto x: test_arr) {
    std::cout << x << " ";
  }
  std::cout << '\n';
}