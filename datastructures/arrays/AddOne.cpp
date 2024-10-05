#include <iostream>
#include <vector>

using std::vector;

vector<int> addOne(const vector<int> &arr) {
  vector<int> new_arr(arr.size());
  int borrow = 1;
  for (int j = arr.size() - 1; j >= 0; --j) {
    const int added_val = arr[j] + borrow;
    borrow = int(added_val / 10);

    new_arr[j] = (borrow == 0) ? added_val : (added_val % 10);
  }
  if (borrow == 1) {
    new_arr.insert(new_arr.begin(), 1);
  }
  return new_arr;
}

int main() {
  vector<int> arr = {9, 9, 9};
  const auto new_arr = addOne(arr);

  std::cout << "[ ";
  for (const auto element : new_arr) {
    std::cout << element << ", ";
  }
  std::cout << "]" << std::endl;
  return EXIT_SUCCESS;
}