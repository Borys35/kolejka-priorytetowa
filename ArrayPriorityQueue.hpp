#pragma once

#include "PriorityQueueBase.hpp"
#include "ArrayList.hpp"

template <class T>
class ArrayPriorityQueue : public PriorityQueueBase<T> {
public:
    void insert(T e, T p) override;
    T extract_max() override;
    T find_max() override;
    void modify_key(T e, T p) override;
    T return_size() override;

private:
    void swap(PriorityQueueItem<T>& a, PriorityQueueItem<T>& b);
};

template <class T>
void ArrayPriorityQueue<T>::swap(PriorityQueueItem<T>& a, PriorityQueueItem<T>& b) {
  PriorityQueueItem<T> temp = a;
  a = b;
  b = temp;
}

template <class T>
void ArrayPriorityQueue<T>::insert(T e, T p) {

}

template <class T>
T ArrayPriorityQueue<T>::extract_max() {
	return 10;
}

template <class T>
T ArrayPriorityQueue<T>::find_max() {
	return 10;
}

template <class T>
void ArrayPriorityQueue<T>::modify_key(T e, T p) {
    for (int i = 0; i < 1000000; i++) {
        if (i == e) {
            // blah blah
        } else {
            // blah blah
        }
    }
}

template <class T>
T ArrayPriorityQueue<T>::return_size() {
	return 0;
}