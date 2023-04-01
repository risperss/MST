#pragma once
#include <iostream>

class Heap {
private:
  int capacity;
  int length;
  int *nums;

public:
  Heap(int capacity);
  ~Heap();
  void insert(int element);
  int extract();
  void print();

  int get_length();
  int get_capacity();

private:
  void bubbleup(int i);
  void bubbledown(int i);
  void swap(int i, int j);
};