#include "filter.h"

Call** filterCalls(
    Call* array[],
    int size,
    bool (*check)(const Call*),
    int& result_size
) {
    result_size = 0;
    for (int i = 0; i < size; ++i) {
        if (check(array[i])) {
            ++result_size;
        }
    }

    Call** result = new Call * [result_size];
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (check(array[i])) {
            result[index++] = array[i];
        }
    }

    return result; 
}

bool isMobileCall(const Call* call) {
    return call->tariff == "мобильный";
}

bool isNovember2021Call(const Call* call) {
    return call->date.substr(3, 7) == "11.2021";
}
