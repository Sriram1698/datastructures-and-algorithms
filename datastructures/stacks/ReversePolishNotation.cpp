#include "Stack.h"

#include <cmath>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

using std::function;
using std::string;
using std::unordered_map;
using std::vector;

using Operations = unordered_map<string, function<int(const int, const int)>>;

template <typename DataType, typename ArrayType>
int applyRPN(const ArrayType &arr) {
  Operations operations;
  operations["+"] = [](const int a, const int b) { return a + b; };
  operations["-"] = [](const int a, const int b) { return a - b; };
  operations["*"] = [](const int a, const int b) { return a * b; };
  operations["/"] = [](const int a, const int b) {
    return (b != 0) ? std::floor(float(a) / float(b)) : 0;
  };

  Stack<int> stk;
  for (auto element : arr) {
    if (operations.find(element) != operations.cend()) {
      const auto e2 = stk.top();
      stk.pop();
      const auto e1 = stk.top();
      stk.pop();
      stk.push(operations[element](e1, e2));
    } else {
      stk.push(std::stoi(element));
    }
  }
  return stk.top();
}

int main() {
  vector<string> str = {"10", "6", "9",  "3", "+", "-11", "*",
                        "/",  "*", "17", "+", "5", "+"};
  std::cout << "Output: " << applyRPN<string>(str) << std::endl;
  return EXIT_SUCCESS;
}