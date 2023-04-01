#include <heap.hpp>

Heap::Heap(int cap) {
  capacity = cap;
  length = 0;
  nums = new int[cap];
}

Heap::~Heap() { delete nums; }

void Heap::insert(int element) {
  if (length == capacity) {
    return;
  }
  nums[length + 1] = element;
  bubbleup(length + 1);
  length++;
}

int Heap::extract() {
  if (length == 0) {
    return -1;
  }
  int min = nums[1];
  nums[1] = nums[length];
  nums[length] = 0;
  length--;
  bubbledown(1);
  return min;
}

void Heap::print() {
  for (int i = 1; i <= length; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << "\n";
}

void Heap::swap(int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

void Heap::bubbleup(int i) {
  if (i == 1) {
    return;
  }

  if (nums[i] < nums[i / 2]) {
    swap(i, i / 2);
    bubbleup(i / 2);
  }
}

void Heap::bubbledown(int i) {
  if (2 * i > length) {
    return;
  } else if (2 * i + 1 > length) {
    // TODO: barf
    if (nums[2 * i] < nums[i]) {
      swap(i, 2 * i);
      bubbledown(2 * i);
    }
    return;
  }
  int idx = -1;

  if (nums[2 * i] <= nums[2 * i + 1]) {
    idx = 2 * i;
  } else {
    idx = 2 * i + 1;
  }

  if (nums[i] > nums[idx]) {
    swap(i, idx);
    bubbledown(idx);
  }
}

int Heap::get_length() { return length; }

int Heap::get_capacity() { return capacity; }
