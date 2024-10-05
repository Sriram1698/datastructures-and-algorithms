#include "Stack.h"
#include <string>

using std::string;

int minimumBracketReversals(const string &str) {
  if (str.length() % 2 != 0) {
    return -1;
  }

  int min_reversals = 0;
  Stack<char> stk;
  for (const char bracket : str) {
    if (stk.empty()) {
      stk.push(bracket);
    } else {
      const auto top = stk.top();
      if ((top != bracket) && (top == '{')) {
        stk.pop();
        continue;
      }
      stk.push(bracket);
    }
  }

  while (!stk.empty()) {
    const char e1 = stk.top();
    stk.pop();
    const char e2 = stk.top();
    stk.pop();
    if ((e1 == '}') && (e2 == '}')) {
      min_reversals += 1;
    } else if ((e1 == '{') && (e2 == '}')) {
      min_reversals += 2;
    } else if ((e1 == '{') && (e2 == '{')) {
      min_reversals += 1;
    }
  }
  return min_reversals;
}

int main() {
  string str = "{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}";
  std::cout << minimumBracketReversals(str) << std::endl;
  return EXIT_SUCCESS;
}