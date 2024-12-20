#include <iostream>

using namespace std;

#include <iostream>
#include <cstring>
#include "tarif.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

// heap sort

void heapify(Call* array[], int n, int i, bool (*compare)(const Call*, const Call*)) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n&& compare(array[largest], array[left])) {
        largest = left;
    }

    if (right < n&& compare(array[largest], array[right])) {
        largest = right;
    }

    if (largest != i) {
        std::swap(array[i], array[largest]);
        heapify(array, n, largest, compare);
    }
}

void heapSort(Call* array[], int size, bool (*compare)(const Call*, const Call*)) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(array, size, i, compare);
    }

    for (int i = size - 1; i > 0; --i) {
        std::swap(array[0], array[i]);
        heapify(array, i, 0, compare);
    }
}
// quick sort
int partition(Call* array[], int low, int high, bool (*compare)(const Call*, const Call*)) {
    Call* pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (compare(pivot, array[j])) {
            ++i;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return i + 1;
}

void quickSort(Call* array[], int low, int high, bool (*compare)(const Call*, const Call*)) {
    if (low < high) {
        int pi = partition(array, low, high, compare);
        quickSort(array, low, pi - 1, compare);
        quickSort(array, pi + 1, high, compare);
    }
}

void quickSortWrapper(Call* array[], int size, bool (*compare)(const Call*, const Call*)) {
    quickSort(array, 0, size - 1, compare);
}

bool compareByDuration(const Call* a, const Call* b) {
    return a->duration < b->duration; 
}

bool compareByNumberAndCost(const Call* a, const Call* b) {
    if (a->number == b->number) {
        return a->cost > b->cost; 
    }
    return a->number > b->number; 
}

void (*sortFunctions[])(Call* [], int, bool (*)(const Call*, const Call*)) = {
       heapSort, quickSortWrapper
};

bool (*compareFunctions[])(const Call*, const Call*) = {
    compareByDuration, compareByNumberAndCost
};


int main(){
    system("chcp 65001");
    cout << "Лабораторная работа №8. GIT\n";
    cout << "Вариант №9. Телефонные разговоры\n";
    cout << "Автор: Петров Станислав\n\n";
    cout << "Группа: 24ПИнж\n";

    const int max_size = 100; 
    Call* calls[max_size];    
    int size;                 

    try {
        read("data.txt", calls, size);

        std::cout << "\nПрочитано " << size << " записей:\n";
        for (int i = 0; i < size; ++i) {
            std::cout << "Номер: " << calls[i]->number
                << ", Дата: " << calls[i]->date
                << ", Время: " << calls[i]->time
                << ", Тариф: " << calls[i]->tariff
                << ", Длительность: " << calls[i]->duration
                << ", Стоимость: " << calls[i]->cost << "\n";
        }

        while (true) {
            std::cout << "\nВыберите действие:\n";
            std::cout << "1. Фильтровать звонки (на мобильные телефоны или ноябрь 2021)\n";
            std::cout << "2. Сортировать звонки\n";
            std::cout << "3. Выход\n";
            std::cout << "Ваш выбор: ";

            int choice;
            std::cin >> choice;

            if (choice == 1) {
                // Фильтрация звонков
                std::cout << "Выберите фильтр:\n";
                std::cout << "1. Звонки на мобильные телефоны\n";
                std::cout << "2. Звонки в ноябре 2021 года\n";
                std::cout << "Ваш выбор: ";

                int filter_choice;
                std::cin >> filter_choice;

                bool (*filter_function)(const Call*) = nullptr;

                if (filter_choice == 1) {
                    filter_function = isMobileCall;
                }
                else if (filter_choice == 2) {
                    filter_function = isNovember2021Call;
                }
                else {
                    std::cout << "Некорректный выбор!\n";
                    continue;
                }

                int filtered_size = 0;
                Call** filtered_calls = filterCalls(calls, size, filter_function, filtered_size);

                std::cout << "\nОтфильтрованные звонки:\n";
                for (int i = 0; i < filtered_size; ++i) {
                    std::cout << "Номер: " << filtered_calls[i]->number
                        << ", Дата: " << filtered_calls[i]->date
                        << ", Время: " << filtered_calls[i]->time
                        << ", Тариф: " << filtered_calls[i]->tariff
                        << ", Длительность: " << filtered_calls[i]->duration
                        << ", Стоимость: " << filtered_calls[i]->cost << "\n";
                }

                delete[] filtered_calls; 
            }
            else if (choice == 2) {
                // Сортировка звонков
                std::cout << "Выберите метод сортировки:\n";
                std::cout << "1. Пирамидальная сортировка (Heap Sort)\n";
                std::cout << "2. Быстрая сортировка (Quick Sort)\n";
                std::cout << "Ваш выбор: ";

                int sort_method;
                std::cin >> sort_method;

                void (*sort_function)(Call * [], int, bool (*)(const Call*, const Call*)) = nullptr;
                if (sort_method == 1) {
                    sort_function = heapSort;
                }
                else if (sort_method == 2) {
                    sort_function = quickSortWrapper;
                }
                else {
                    std::cout << "Некорректный выбор!\n";
                    continue;
                }

                std::cout << "Выберите критерий сортировки:\n";
                std::cout << "1. По убыванию длительности звонка\n";
                std::cout << "2. По возрастанию номера телефона (в рамках номера по убыванию стоимости)\n";
                std::cout << "Ваш выбор: ";

                int compare_choice;
                std::cin >> compare_choice;

                bool (*compare_function)(const Call*, const Call*) = nullptr;
                if (compare_choice == 1) {
                    compare_function = compareByDuration;
                }
                else if (compare_choice == 2) {
                    compare_function = compareByNumberAndCost;
                }
                else {
                    std::cout << "Некорректный выбор!\n";
                    continue;
                }

                sort_function(calls, size, compare_function);

                std::cout << "\nОтсортированные звонки:\n";
                for (int i = 0; i < size; ++i) {
                    std::cout << "Номер: " << calls[i]->number
                        << ", Дата: " << calls[i]->date
                        << ", Время: " << calls[i]->time
                        << ", Тариф: " << calls[i]->tariff
                        << ", Длительность: " << calls[i]->duration
                        << ", Стоимость: " << calls[i]->cost << "\n";
                }
            }
            else if (choice == 3) {
                break;
            }
            else {
                std::cout << "Некорректный выбор!\n";
            }
        }

        for (int i = 0; i < size; ++i) {
            delete calls[i];
        }

    }
    catch (const char* error) {
        std::cerr << error << "\n";
    }

    return 0;
}