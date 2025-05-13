#include "TestPriorityQueues.h"
#include <iostream>
#include "HeapPriorityQueue.hpp"
#include "ArrayPriorityQueue.hpp"

void testHeapPriorityQueue() {
    std::cout << "\n===== Test HeapPriorityQueue =====\n";
    HeapPriorityQueue<int> queue;

    std::cout << "Dodawanie elementow: (5,50), (8,80), (3,30), (1,10), (7,70)...\n";
    queue.insert(5, 50);
    queue.insert(8, 80);
    queue.insert(3, 30);
    queue.insert(1, 10);
    queue.insert(7, 70);

    std::cout << "Rozmiar kolejki: " << queue.return_size() << std::endl;
    std::cout << "Element o najwyzszym priorytecie: " << queue.find_max() << std::endl;

    std::cout << "Pobieranie elementow w kolejnosci malejacych priorytetow:\n";
    while (queue.return_size() > 0) {
        std::cout << queue.extract_max() << " ";
    }
    std::cout << std::endl;

    std::cout << "Dodawanie elementow ponownie...\n";
    queue.insert(5, 50);
    queue.insert(8, 80);
    queue.insert(3, 30);
    queue.insert(1, 10);
    queue.insert(7, 70);

    std::cout << "Modyfikacja priorytetu (5 -> 100)...\n";
    queue.modify_key(5, 100);

    std::cout << "Element o najwyzszym priorytecie po modyfikacji: " << queue.find_max() << std::endl;

    std::cout << "Pobieranie elementow po modyfikacji:\n";
    while (queue.return_size() > 0) {
        std::cout << queue.extract_max() << " ";
    }
    std::cout << std::endl;
}

void testArrayPriorityQueue() {
    std::cout << "\n===== Test ArrayPriorityQueue =====\n";
    ArrayPriorityQueue<int> queue;

    std::cout << "Dodawanie elementow: (5,50), (8,80), (3,30), (1,10), (7,70)...\n";
    queue.insert(5, 50);
    queue.insert(8, 80);
    queue.insert(3, 30);
    queue.insert(1, 10);
    queue.insert(7, 70);

    std::cout << "Rozmiar kolejki: " << queue.return_size() << std::endl;
    std::cout << "Element o najwyższym priorytecie: " << queue.find_max() << std::endl;

    std::cout << "Pobieranie elementow w kolejnosci malejacych priorytetow:\n";
    while (queue.return_size() > 0) {
        std::cout << queue.extract_max() << " ";
    }
    std::cout << std::endl;

    std::cout << "Dodawanie elementow ponownie...\n";
    queue.insert(5, 50);
    queue.insert(8, 80);
    queue.insert(3, 30);
    queue.insert(1, 10);
    queue.insert(7, 70);

    std::cout << "Modyfikacja priorytetu (5 -> 100)...\n";
    queue.modify_key(5, 100);

    std::cout << "Element o najwyzszym priorytecie po modyfikacji: " << queue.find_max() << std::endl;

    std::cout << "Pobieranie elementow po modyfikacji:\n";
    while (queue.return_size() > 0) {
        std::cout << queue.extract_max() << " ";
    }
    std::cout << std::endl;
}

void runAllTests() {
    std::cout << "Uruchamianie testow implementacji kolejek priorytetowych\n";
    std::cout << "=============================================\n";

    testHeapPriorityQueue();
    testArrayPriorityQueue();

    std::cout << "\nTesty zakonczone.\n";
}