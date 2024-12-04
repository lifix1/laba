#ifndef TARIF_H
#define TARIF_H

#include "constants.h"

struct date
{
    int day;
    int month;
    int year;
};

struct time
{
    int second;
    int minute;
    int hour;
};

struct tarif
{
    char phone_number[MAX_STRING_SIZE];
    date call_date;
    time duration;
    char title;
    int price;
};


#endif