#include "Stack.h"

#include <string>

using std::string;

bool checkForBalance(const string &s) {
  if (s.length() == 0) {
    return true;
  }

  Stack<char> stk;
  for (auto ch : s) {
    if (ch == '(') {
      stk.push(ch);
    } else if (ch == ')') {
      auto top = stk.top();
      stk.pop();
      if (top == char(NULL)) {
        return false;
      }
    }
  }

  if (stk.empty()) {
    return true;
  }
  return false;
}

int main() {
  string s = "(()())())";
  std::cout << checkForBalance(s) << std::endl;
  return EXIT_SUCCESS;
}