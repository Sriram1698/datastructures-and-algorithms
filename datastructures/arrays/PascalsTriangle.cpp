#include <cmath>
#include <iostream>
#include <vector>

using std::vector;

vector<int> pascalTriangle(const int n) {
  if (n == 0) {
    return {1};
  }

  vector<int> pascals_triangle(n + 1);
  pascals_triangle[0] = 1;

  for (int i = 1; i <= n; i++) {
    pascals_triangle[i] = ((pascals_triangle[i - 1] * (n - i + 1)) / i);
  }
  return pascals_triangle;
}

int main() {
  int n = 4;
  const auto pascals_triangle = pascalTriangle(n);
  std::cout << "[ ";
  for (const auto element : pascals_triangle) {
    std::cout << element << ", ";
  }
  std::cout << "]" << std::endl;
  return EXIT_SUCCESS;
}