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
    T return_size() override;

private:
    void heapify(int i);
    void heapify_up(int i);
    void build_max_heap();
    void swap(PriorityQueueItem<T>& a, PriorityQueueItem<T>& b);
    ArrayList<PriorityQueueItem<T>> heap;
};

template <class T>
void HeapPriorityQueue<T>::heapify(int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < heap.count() && heap.get(l) > heap.get(largest)) {
        largest = l;
    }
    if (r < heap.count() && heap.get(r) > heap.get(largest)) {
        largest = r;
    }

    if (largest != i) {
        swap(heap.get(i), heap.get(largest));
        heapify(largest);
    }
}

template<class T>
void HeapPriorityQueue<T>::heapify_up(int i) {
    int largest = (i - 1) / 2;
    if (i > 0 && heap.get(i) > heap.get(largest)) {
        swap(heap.get(i), heap.get(largest));
        heapify_up(largest);
    }
}


template <class T>
void HeapPriorityQueue<T>::build_max_heap() {
    for (int i = heap.count() / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

template <class T>
void HeapPriorityQueue<T>::swap(PriorityQueueItem<T>& a, PriorityQueueItem<T>& b) {
  PriorityQueueItem<T> temp = a;
  a = b;
  b = temp;
}

template <class T>
void HeapPriorityQueue<T>::insert(T e, T p) {
	PriorityQueueItem<T> item = {e, p};

	heap.push_back(item);

	heapify_up(heap.count() - 1);
}

template <class T>
T HeapPriorityQueue<T>::extract_max() {
	swap(heap.get(0), heap.get(heap.count() - 1));
	PriorityQueueItem<T> max = heap.pop_back();

	heapify(0);

	return max.value;
}

template <class T>
T HeapPriorityQueue<T>::find_max() {
	return heap.get(0).value;
}

template <class T>
void HeapPriorityQueue<T>::modify_key(T e, T p) {
    int index = heap.search({e, p});

    if (index != -1) {
        int oldPriority = heap.get(index).priority;

        heap.get(index).priority = p;

        if (p > oldPriority) {
            heapify_up(index);
        } else {
            heapify(index);
        }
    }
}

template <class T>
T HeapPriorityQueue<T>::return_size() {
	return heap.count();
}