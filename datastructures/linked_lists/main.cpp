#include "LinkedList.h"

#include <vector>

using std::vector;

int main() {

  vector<int> arr1 = {9, 0, 2, 1, 4, 5, 6, 7, 4, 3, 9, 0, 100, 19, 1, 2, 0};
  vector<int> arr2 = {12, 8, 5, 23, 8, 145, 9, 0, 17, -1, -3};

  LinkedList<int> list_1(arr1.begin(), arr1.end());
  LinkedList<int> list_2(arr2.begin(), arr2.end());

  vector<LinkedList<int> > lists = {list_1, list_2};
  std::cout << "Input: \n";
  for (auto& lst : lists)
  {
    lst.print();
  }

  std::cout << "Merge two arrays in sorted manner" << std::endl;
  auto merged_list = lists[0];
  for (int i = 1; i < lists.size(); i++)
  {
    merged_list.merge(lists[i]);
  }
  merged_list.print();
  return EXIT_SUCCESS;
}