#include <cmath>
#include <iostream>
#include <vector>

using std::abs;
using std::vector;

int findDuplicate(vector<int> arr) {
  int index = 0;
  size_t size = arr.size();
  while (index < size) {
    int val = abs(arr[index]);
    if (arr[val] < 0) {
      return val;
    } else {
      arr[val] *= -1;
    }
    index++;
  }
  return -1;
}

int main() {
  vector<int> arr = {0, 2, 3, 2, 4, 5, 1};
  std::cout << findDuplicate(arr) << std::endl;
  return EXIT_SUCCESS;
}