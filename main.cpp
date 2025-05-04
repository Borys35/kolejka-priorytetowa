#include <iostream>
#include "HeapPriorityQueue.hpp"

int main() {
    std::cout << "Heap Priority Queue!" << std::endl;

    HeapPriorityQueue<int> heapQueue;

    heapQueue.insert(2,2);
    heapQueue.insert(1,1);
    heapQueue.insert(3,3);
    heapQueue.insert(4,4);
    heapQueue.insert(8,8);
    heapQueue.insert(5,5);
    heapQueue.insert(6,6);

    int max_v = heapQueue.find_max();
    std::cout << "Value with max priority: " << max_v << std::endl;
    int size = heapQueue.return_size();
    std::cout << "Size: " << size << std::endl;
    heapQueue.extract_max();
    max_v = heapQueue.find_max();
    std::cout << "Value with max priority after extracting: " << max_v << std::endl;
    size = heapQueue.return_size();
    std::cout << "Size: " << size << std::endl;
    heapQueue.extract_max();
    max_v = heapQueue.find_max();
    std::cout << "Value with max priority after extracting: " << max_v << std::endl;
    size = heapQueue.return_size();
    std::cout << "Size: " << size << std::endl;

    std::cout << "====== MODIFY KEY ======" << std::endl;

    heapQueue.modify_key(5, 1);
    max_v = heapQueue.find_max();
    std::cout << "Value with max priority after modifying: " << max_v << std::endl;

    return 0;
}