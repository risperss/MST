#include <heap.hpp>
#include <iostream>

int main(void) {
  std::cout << "Hello World\n";

  Heap heap = Heap(10);

  heap.insert(10);
  heap.insert(3);
  heap.insert(2);
  heap.insert(4);
  heap.insert(5);
  heap.insert(15);
  heap.print();

  int l = heap.get_length();
  for (int i = 1; i <= l; i++) {
    std::cout << heap.extract() << "\n";
    heap.print();
  }
  return 0;
}
