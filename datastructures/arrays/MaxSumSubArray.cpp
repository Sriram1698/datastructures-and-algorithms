#include <algorithm>
#include <iostream>
#include <vector>

using std::max;
using std::vector;

int getMaxSubArraySum(const vector<int> &arr) {
  if (arr.size() == 0) {
    return 0;
  }
  int current_sum = arr[0];
  int max_sum = arr[0];

  for (int i = 1; i < arr.size(); ++i) {
    current_sum = max(current_sum + arr[i], arr[i]);
    max_sum = max(current_sum, max_sum);
  }
  return max_sum;
}

int main() {
  vector<int> arr = {1, 2, -5, -4, 1, 6};
  std::cout << getMaxSubArraySum(arr) << std::endl;
  return EXIT_SUCCESS;
}