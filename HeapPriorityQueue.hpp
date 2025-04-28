#pragma once

#include "PriorityQueueBase.hpp"

template <class T>
class HeapPriorityQueue : public PriorityQueueBase<T> {
public:
    void insert(T e, T p) override;
    void extract_max() override;
    void find_max() override;
    void modify_key(T e, T p) override;
    void return_size() override;

private:
  void heapify(int i);
  void build_max_heap();
  void swap(PriorityQueueItem<T>& a, PriorityQueueItem<T>& b);
  PriorityQueueItem<T> heap_arr[32];
};

template <class T>
void HeapPriorityQueue<T>::heapify(int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < this->size && heap_arr[l] > heap_arr[i]) {
        largest = l;
    }
    if (r < this->size & heap_arr[r] > heap_arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(heap_arr[i], heap_arr[largest]);
        heapify(largest);
    }
}

template <class T>
void HeapPriorityQueue<T>::build_max_heap() {
    for (int i = this->size / 2 - 1; i >= 0; i--) {
      heapify(i);
    }
}

template <class T>
void HeapPriorityQueue<T>::swap(PriorityQueueItem<T>& a, PriorityQueueItem<T>& b) {
  T temp = a;
  a = b;
  b = temp;
}