#ifndef FILTER_H
#define FILTER_H

#include "tarif.h"
#include <vector>


Call** filterCalls(
    Call* array[],
    int size,
    bool (*check)(const Call*),
    int& result_size
);

bool isMobileCall(const Call* call);

bool isNovember2021Call(const Call* call);

#endif
