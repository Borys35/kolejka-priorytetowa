#pragma once

template<typename T>
struct PriorityQueueItem {
    T value;
    T priority;
};

template<class T>
class PriorityQueueBase {
public:
    virtual ~PriorityQueueBase() = default;

    virtual void insert(T e, T p) = 0;
    virtual void extract_max() = 0;
    virtual void find_max() = 0;
    virtual void modify_key(T e, T p) = 0;
    virtual void return_size() = 0;

protected:
    int size = 0;
};