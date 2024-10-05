#include <iostream>
#include <vector>

using std::vector;

int nPossibleSteps(const int n) {
  if (n <= 1) {
    return 1;
  }
  else if (n == 2) {
    return 2;
  }
  else if (n == 3) {
    return 4;
  }

  return nPossibleSteps(n - 1) + nPossibleSteps(n - 2) + nPossibleSteps(n - 3);
}

int main() {
  std::cout << nPossibleSteps(4) << std::endl;
  return EXIT_SUCCESS;
}