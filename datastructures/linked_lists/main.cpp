#include "LinkedList.h"

#include <vector>

using std::vector;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    LinkedList<int> linked_list(arr.begin(), arr.end());
    linked_list.print();
    linked_list.erase(3);
    linked_list.print();
    linked_list.insert(9, 4);
    linked_list.print();
    return EXIT_SUCCESS;
}