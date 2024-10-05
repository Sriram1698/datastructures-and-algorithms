#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

char getChar(const int val) { return static_cast<char>(val + 'a' - 1); }

vector<string> getCodes(const int val) {
  if (val == 0) {
    return {""};
  }

  const auto remainder_100 = val % 100;
  vector<string> output_100;
  if ((remainder_100 <= 26) && (val > 9)) {
    output_100 = getCodes(int(std::floor(float(val) / 100.)));
    const auto alphabet = getChar(remainder_100);

    for (size_t i = 0; i < output_100.size(); i++) {
      output_100[i] += alphabet;
    }
  }

  const auto remainder_10 = val % 10;
  vector<string> output_10 = getCodes(int(std::floor(float(val) / 10.)));
  const auto alphabet = getChar(remainder_10);
  for (size_t i = 0; i < output_10.size(); i++) {
    output_10[i] += alphabet;
  }
  vector<string> output(0);
  output.insert(output.end(), output_100.cbegin(), output_100.cend());
  output.insert(output.end(), output_10.cbegin(), output_10.cend());
  return output;
}

int main() {
  const auto codes = getCodes(14512);
  std::cout << "[ ";
  for (const auto &code : codes) {
    std::cout << code << ", ";
  }
  std::cout << "]" << std::endl;
  return EXIT_SUCCESS;
}