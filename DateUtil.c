//
// Created by b00877391 on 7/12/2024.
//
#include "DateUtil.h"

bool isLeapYear(const int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

bool isValidDate(const int day, const int month, const int year)
{
    if (month > 12 || day > 31 || day < 0 || month < 0 || year < 0) {
        return false;
    }
    int days = isLeapYear(year) && month == 2 ? 29 : dayOfMonths[month];

    return day <= days;
}

