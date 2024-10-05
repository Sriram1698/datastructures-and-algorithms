#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;

vector<vector<int>> permutations(const vector<int> &arr) {
  vector<vector<int>> final_permuatations(0);
  if (arr.empty()) {
    return {{}};
  }
  auto first_element = arr[0];
  vector<int> sub_arr(arr.cbegin() + 1, arr.cend());
  auto sub_components = permutations(sub_arr);

  for (auto vec : sub_components) {
    vector<int> new_vec(0);
    for (int j = 0; j <= vec.size(); j++) {
      new_vec = vec;
      new_vec.insert(new_vec.begin() + j, first_element);
      final_permuatations.push_back(new_vec);
    }
  }
  return final_permuatations;
}

int main() {
  vector<int> arr = {0, 1, 2};
  auto final_permuatations = permutations(arr);
  std::cout << "[";
  for (auto vec : final_permuatations) {
    std::cout << "[";
    for (auto val : vec) {
      std::cout << val << ", ";
    }
    std::cout << "], ";
  }
  std::cout << "]" << std::endl;
  return EXIT_SUCCESS;
}