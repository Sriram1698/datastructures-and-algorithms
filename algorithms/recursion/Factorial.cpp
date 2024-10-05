#include <iostream>

int factorialOf(const int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorialOf(n - 1);
}

int main() {
  std::cout << factorialOf(5) << std::endl;
  return EXIT_SUCCESS;
}