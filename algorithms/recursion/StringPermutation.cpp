#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> permutations(string str) {
  vector<string> final_permuatations(0);
  if (str.empty()) {
    return {""};
  }
  auto first_element = str[0];
  string sub_str = str.substr(1, str.length() - 1);
  auto sub_components = permutations(sub_str);

  for (auto sstr : sub_components) {
    string new_str = "";
    for (int j = 0; j <= sstr.length(); j++) {
      new_str = sstr;
      new_str.insert(new_str.begin() + j, first_element);
      final_permuatations.push_back(new_str);
    }
  }
  return final_permuatations;
}

int main() {
  string str = "abdc";
  auto final_permuatations = permutations(str);
  std::cout << "[";
  for (auto str : final_permuatations) {
    std::cout << "[\"";
    std::cout << str;
    std::cout << "\"], ";
  }
  std::cout << "]" << std::endl;
  return EXIT_SUCCESS;
}