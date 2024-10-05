#include <cmath>
#include <iostream>
#include <vector>

using std::vector;

int getIndex(const vector<int> &arr, const int start_index, const int end_index,
             const int target) {
  if (start_index > end_index) {
    return -1;
  }
  const int mid_index = std::floor((float(start_index + end_index)) / 2.);

  if (arr[mid_index] == target) {
    return mid_index;
  } else if (arr[mid_index] > target) {
    return getIndex(arr, start_index, mid_index - 1, target);
  } else {
    return getIndex(arr, mid_index + 1, end_index, target);
  }
}

int getIndex(const vector<int> &arr, const int target) {
  return getIndex(arr, 0, arr.size() - 1, target);
}

int main() {
  vector<int> arr = {8, 2, 34, 5, 6, 7, 78, 12};
  int target = 7;
  std::cout << getIndex(arr, target) << std::endl;
  return EXIT_SUCCESS;
}