//
// Created by User on 14.04.2025.
//
#include "TestGenerator.hpp"
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

//                ArrayList<int> arrayList;
//                SinglyLinkedList<int> singlyLinkedList;
//                DoublyLinkedList<int> doublyLinkedList;

                HeapPriorityQueue<int> maxHeap;

                // Inicjalizacja list
                int *baseArray = new int[size];
                fillArray(baseArray, size);

                arrayToList(size, baseArray, [&](int value) { arrayList.push_back(value); });
                arrayToList(size, baseArray, [&](int value) { singlyLinkedList.push_back(value); });
                arrayToList(size, baseArray, [&](int value) { doublyLinkedList.push_back(value); });

                int randomValue = rand() % 1001;
                int randomIndex = rand() % size;

                // Wartość do wyszukania - losowa wartość z tablicy lub spoza tablicy
                int valueToSearch;
                if (rand() % 2 == 0) {
                    // Wybierz losowy element z tablicy
                    valueToSearch = baseArray[rand() % size];
                } else {
                    // Wygeneruj prawdopodobnie nieistniejącą wartość
                    valueToSearch = 1001 + rand() % 1000;
                }

                // ArrayList
                long long durationArray;
                if (operacja == "push_back") {
                    durationArray = measureTime([&]() { arrayList.push_back(randomValue); });
                } else if (operacja == "push_front") {
                    durationArray = measureTime([&]() { arrayList.push_front(randomValue); });
                } else if (operacja == "insert") {
                    durationArray = measureTime([&]() { arrayList.insert(randomValue, randomIndex); });
                } else if (operacja == "remove_back") {
                    durationArray = measureTime([&]() { arrayList.remove_back(); });
                } else if (operacja == "remove_front") {
                    durationArray = measureTime([&]() { arrayList.remove_front(); });
                } else if (operacja == "remove") {
                    durationArray = measureTime([&]() { arrayList.remove(randomIndex); });
                } else if (operacja == "get") {
                    durationArray = measureTime([&]() { arrayList.get(randomIndex); });
                } else if (operacja == "search") {
                    durationArray = measureTime([&]() { arrayList.search(valueToSearch); });
                } else {
                    durationArray = 0;
                }
                file << durationArray << ",";

                // SinglyLinkedList
                long long durationSingly;
                if (operacja == "push_back") {
                    durationSingly = measureTime([&]() { singlyLinkedList.push_back(randomValue); });
                } else if (operacja == "push_front") {
                    durationSingly = measureTime([&]() { singlyLinkedList.push_front(randomValue); });
                } else if (operacja == "insert") {
                    durationSingly = measureTime([&]() { singlyLinkedList.insert(randomValue, randomIndex); });
                } else if (operacja == "remove_back") {
                    durationSingly = measureTime([&]() { singlyLinkedList.remove_back(); });
                } else if (operacja == "remove_front") {
                    durationSingly = measureTime([&]() { singlyLinkedList.remove_front(); });
                } else if (operacja == "remove") {
                    durationSingly = measureTime([&]() { singlyLinkedList.remove(randomIndex); });
                } else if (operacja == "get") {
                    durationSingly = measureTime([&]() { singlyLinkedList.get(randomIndex); });
                } else if (operacja == "search") {
                    durationSingly = measureTime([&]() { singlyLinkedList.search(valueToSearch); });
                } else {
                    durationSingly = 0;
                }
                file << durationSingly << ",";

                // DoublyLinkedList
                long long durationDoubly;
                if (operacja == "push_back") {
                    durationDoubly = measureTime([&]() { doublyLinkedList.push_back(randomValue); });
                } else if (operacja == "push_front") {
                    durationDoubly = measureTime([&]() { doublyLinkedList.push_front(randomValue); });
                } else if (operacja == "insert") {
                    durationDoubly = measureTime([&]() { doublyLinkedList.insert(randomValue, randomIndex); });
                } else if (operacja == "remove_back") {
                    durationDoubly = measureTime([&]() { doublyLinkedList.remove_back(); });
                } else if (operacja == "remove_front") {
                    durationDoubly = measureTime([&]() { doublyLinkedList.remove_front(); });
                } else if (operacja == "remove") {
                    durationDoubly = measureTime([&]() { doublyLinkedList.remove(randomIndex); });
                } else if (operacja == "get") {
                    durationDoubly = measureTime([&]() { doublyLinkedList.get(randomIndex); });
                } else if (operacja == "search") {
                    durationDoubly = measureTime([&]() { doublyLinkedList.search(valueToSearch); });
                } else {
                    durationDoubly = 0;
                }
                file << durationDoubly << "\n";

                delete[] baseArray;
            }
            std::cout << "Zakonczono testy dla operacji " << operacja << " na rozmiarze " << size << std::endl;
        }
    }

    file.close();
    std::cout << "Wyniki zapisano do pliku data.txt" << std::endl;
}