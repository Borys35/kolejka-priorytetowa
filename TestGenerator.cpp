#include "TestGenerator.hpp"
#include "ArrayPriorityQueue.hpp"
#include "HeapPriorityQueue.hpp"

void generateTests() {
    std::ofstream file;
    file.open("./data.txt", std::ios::out | std::ios::trunc);

    if (!file.is_open()) {
        std::cout << "Plik nie moze zostac otworzony" << std::endl;
        return;
    }

    std::cout << "Generowanie testow\n";

    int sizes[8] = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};
    std::vector<std::string> operacje = {"insert", "extract_max", "find_max", "modify_key", "return_size"};

    file << "nr.,rozmiar,operacja,kopiec,inna\n";

    for (int i = 0; i < 8; i++) {
        int size = sizes[i];
        for (const auto& operacja : operacje) {
            // ilosc testow na jedna operacje
            for (int j = 0; j < 100; j++) {
                file << j + 1 << "," << size << "," << operacja << ",";

                HeapPriorityQueue<int> heapQueue;
                ArrayPriorityQueue<int> arrayQueue;

                // Inicjalizacja list
                int *valueArray = new int[size];
                int *priorityArray = new int[size];

                // Ustawiamy inny seed dla każdego przypadku
                srand(time(nullptr));

                fillArray(valueArray, priorityArray, size);

                arrayToList(size, valueArray, priorityArray, [&](int v, int p) { heapQueue.insert(v, p); });
                arrayToList(size, valueArray, priorityArray, [&](int v, int p) { arrayQueue.insert(v, p); });

                int rValue = rand() % 1001;
                int rPriority = rand() % 10001;

                // Heap Priority Queue
                long long durationHeap;
                if (operacja == "insert") {
                    durationHeap = measureTime([&]() { heapQueue.insert(rValue, rPriority); });
                } else if (operacja == "extract_max") {
                    durationHeap = measureTime([&]() { heapQueue.extract_max(); });
                } else if (operacja == "find_max") {
                    durationHeap = measureTime([&]() { heapQueue.find_max(); });
                } else if (operacja == "modify_key") {
                    durationHeap = measureTime([&]() { heapQueue.modify_key(rValue, rPriority); });
                } else if (operacja == "return_size") {
                    durationHeap = measureTime([&]() { heapQueue.return_size(); });
                } else {
                    durationHeap = 0;
                }
                file << durationHeap << ",";

                // Array Priority Queue
                long long durationArray;
                if (operacja == "insert") {
                    durationArray = measureTime([&]() { arrayQueue.insert(rValue, rPriority); });
                } else if (operacja == "extract_max") {
                    durationArray = measureTime([&]() { arrayQueue.extract_max(); });
                } else if (operacja == "find_max") {
                    durationArray = measureTime([&]() { arrayQueue.find_max(); });
                } else if (operacja == "modify_key") {
                    durationArray = measureTime([&]() { arrayQueue.modify_key(rValue, rPriority); });
                } else if (operacja == "return_size") {
                    durationArray = measureTime([&]() { arrayQueue.return_size(); });
                } else {
                    durationArray = 0;
                }
                file << durationArray << "\n";

                delete [] valueArray;
                delete [] priorityArray;
            }
            std::cout << "Zakonczono testy dla operacji " << operacja << " na rozmiarze " << size << std::endl;
        }
    }

    file.close();
    std::cout << "Wyniki zapisano do pliku data.txt" << std::endl;
}