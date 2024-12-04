#ifndef TARIF_H
#define TARIF_H

#include "constants.h"

struct date
{
    int day;
    int month;
    int year;
};

struct start_time
{
    int second;
    int minute;
    int hour;
};

struct tarif
{
    char phone_number[MAX_STRING_SIZE];
    date call_date;
    start_time duration;
    char title[MAX_STRING_SIZE];
    char price[MAX_STRING_SIZE];
};


#endif