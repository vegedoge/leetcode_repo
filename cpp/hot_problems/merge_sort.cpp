#include <vector>
#include <iostream>

void merge(std::vector<int>& arr, int left, int mid, int right) {
  // 计算两个数组大小
  int sub_arr_1 = mid - left + 1;
  int sub_arr_2 = right - mid;

  // 临时数组 O(n) 来源
  std::vector<int> left_array(sub_arr_1);
  std::vector<int> right_array(sub_arr_2);

  // copy
  for (int i = 0; i < sub_arr_1; ++i) {
    left_array[i] = arr[left + i];
  }

  for (int j = 0; j < sub_arr_2; ++i) {
    right_array[j] = arr[mid + j];
  }

  // 合并回去
  int index_of_left_arr = 0;
  int index_of_right_arr = 0;
  int index_of_merged_arr = left;

  while (index_of_left_arr < sub_arr_1 && index_of_right_arr < sub_arr_2) {
    if (left_array[index_of_left_arr] <= right_array[index_of_right_arr]) {
      arr[index_of_merged_arr] = left_array[index_of_left_arr];
      index_of_left_arr++;
    } else {
      arr[index_of_merged_arr] = right_array[index_of_right_arr];
      index_of_right_arr++;
    }

    index_of_merged_arr++;
  }

  // 5. 将左子数组中剩余的元素复制到主数组
  while (index_of_left_array < sub_array_one) {
      arr[index_of_merged_array] = left_array[index_of_left_array];
      index_of_left_array++;
      index_of_merged_array++;
  }

  // 6. 将右子数组中剩余的元素复制到主数组
  while (index_of_right_array < sub_array_two) {
      arr[index_of_merged_array] = right_array[index_of_right_array];
      index_of_right_array++;
      index_of_merged_array++;
  }
}

void merge_sort(std::vector<int>& arr, int begin, int end) {
  if (begin >= end) {
    return;
  }

  int mid = begin + (end - begin) / 2;
  merge_sort(arr, begin, mid);
  merge_sort(arr, mid + 1, end);

  merge(arr, begin, mid, end);
}

// 辅助函数，打印数组
void print_array(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = {12, 11, 13, 5, 6, 7};
    std::cout << "Original array: ";
    print_array(data);

    merge_sort(data, 0, data.size() - 1);

    std::cout << "Sorted array: ";
    print_array(data);

    return 0;
}