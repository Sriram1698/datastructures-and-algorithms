#include <iostream>

void towerOfHanoi(const int n_disks, const char source = 'S',
                  const char auxiliary = 'A', const char destination = 'D') {
  if (n_disks == 0) {
    return void(0);
  }

  if (n_disks == 1) {
    std::cout << source << " " << destination << std::endl;
    return;
  }

  towerOfHanoi(n_disks - 1, source, destination, auxiliary);
  std::cout << source << " " << destination << std::endl;

  towerOfHanoi(n_disks - 1, auxiliary, source, destination);
}

int main() {
  towerOfHanoi(3);
  return EXIT_SUCCESS;
}