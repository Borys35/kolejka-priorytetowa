#pragma once

#include "PriorityQueueBase.hpp"
#include "ArrayList.hpp"

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
    ArrayList<PriorityQueueItem<T>> heap;
};

template <class T>
void HeapPriorityQueue<T>::heapify(int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < this->size && heap.get(l) > heap.get(largest)) {
        largest = l;
    }
    if (r < this->size & heap[r] > heap.get(largest)) {
        largest = r;
    }

    if (largest != i) {
        swap(heap.get(i), heap.get(largest));
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