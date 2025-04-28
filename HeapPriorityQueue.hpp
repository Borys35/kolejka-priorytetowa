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
    PriorityQueueItem<T> heap[32];
};

template <class T>
void HeapPriorityQueue<T>::insert(T e, T p) {

}