#include <iostream>
#include <string>

using std::string;

string reverseString(string str) {
  if (str.length() == 0) {
    return "";
  }
  return str[str.length() - 1] + reverseString(str.substr(0, str.length() - 1));
}

int main() {
  string str = "Water Vapour";
  std::cout << reverseString(str) << std::endl;
  return EXIT_SUCCESS;
}
