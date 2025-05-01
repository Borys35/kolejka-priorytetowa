#pragma once

#include "PriorityQueueBase.hpp"
#include "ArrayList.hpp"

template <class T>
class HeapPriorityQueue : public PriorityQueueBase<T> {
public:
    void insert(T e, T p) override;
    T extract_max() override;
    T find_max() override;
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

template <class T>
void HeapPriorityQueue<T>::insert(T e, T p) {
	PriorityQueueItem<T> item;
	item.value = e;
	item.priority = p;

	heap.push_back(item);

	build_max_heap();
}

template <class T>
T HeapPriorityQueue<T>::extract_max() {
	swap(heap.get(0), heap.get(heap.size - 1));
	T max = heap.pop_back();
	build_max_heap();
	return max;
}

template <class T>
T HeapPriorityQueue<T>::find_max() {
	return heap.get(0);
}

template <class T>
void HeapPriorityQueue<T>::modify_key(T e, T p) {
    PriorityQueueItem<T> item;
    item.value = e;
    item.priority = p;
}

template <class T>
void HeapPriorityQueue<T>::return_size() {
	return heap.count();
}