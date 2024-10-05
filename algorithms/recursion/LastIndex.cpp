#include <iostream>
#include <vector>

using std::vector;

int getLastElementIndex(const vector<int> &arr, const int target,
                        const int last_index) {
  if (last_index < 0) {
    return -1;
  }
  if (arr[last_index] == target) {
    return last_index;
  }
  return getLastElementIndex(arr, target, last_index - 1);
}

int getLastIndex(const vector<int> &arr, const int target) {
  return getLastElementIndex(arr, target, arr.size() - 1);
}

int main() {
  vector<int> arr = {1, 2, 5, 5, 4, 7, 7, 4, 9, 7, 250, 7, 6, 5};
  int target = 7;
  std::cout << "Last occurance index of " << target << " is " << getLastIndex(arr, target) << std::endl;
  return EXIT_SUCCESS;
}