#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

struct KeyChar {
public:
  KeyChar() {
    key_combinations[0] = "";
    key_combinations[1] = "";
    key_combinations[2] = "abc";
    key_combinations[3] = "def";
    key_combinations[4] = "ghi";
    key_combinations[5] = "jkl";
    key_combinations[6] = "mno";
    key_combinations[7] = "pqrs";
    key_combinations[8] = "tuv";
    key_combinations[9] = "wxyz";
  }
  string getStr(const int num) { return key_combinations[num]; }

private:
  unordered_map<int, string> key_combinations;
} keychar;

vector<string> keypad(const int num) {
  vector<string> permutations;
  if ((num >= 0) && (num <= 9)) {
    string str = keychar.getStr(num);
    permutations.resize(str.length());
    std::transform(str.cbegin(), str.cend(), permutations.begin(),
                   [](const char c) { return string(1, c); });
    return permutations;
  }

  int last_digit = num % 10;
  auto small_output = keypad(int(std::floor(float(num) / 10.)));
  const string keypad_string = keychar.getStr(last_digit);

  for (const char ch : keypad_string) {
    for (const string str : small_output) {
      permutations.push_back(str + ch);
    }
  }
  return permutations;
}

int main() {
  const int num = 354;
  const auto permutations = keypad(num);
  std::cout << "[ ";
  for (const auto perm : permutations) {
    std::cout << perm << ", ";
  }
  std::cout << "]" << std::endl;
}