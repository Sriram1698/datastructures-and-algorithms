#include <iostream>
#include <vector>

using std::vector;

vector<vector<int>> getAllSubsets(const vector<int> &arr, const int index = 0) {
  if (index >= arr.size()) {
    return {{}};
  }

  const auto sub_output = getAllSubsets(arr, index + 1);
  vector<vector<int>> output(0);
  for (const auto element : sub_output) {
    output.push_back(element);
  }

  for (const auto element : sub_output) {
    vector<int> current(0);
    current.push_back(arr[index]);
    current.insert(current.end(), element.cbegin(), element.cend());
    output.push_back(current);
  }
  return output;
}

int main() {
  vector<int> arr = {9, 12, 15};
  const auto subsets = getAllSubsets(arr);
  std::cout << "[ \n";
  for (const auto subset : subsets) {
    std::cout << "[ ";
    for (auto val : subset) {
      std::cout << val << ", ";
    }
    std::cout << "], \n";
  }
  std::cout << "]" << std::endl;
  return EXIT_SUCCESS;
}