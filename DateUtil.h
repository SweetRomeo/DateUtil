//
// Created by b00877391 on 7/12/2024.
//

#ifndef DATEUTIL_H
#define DATEUTIL_H
#include <stdbool.h>
int dayOfMonths[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool isLeapYear(int year);
bool isValidDate(int day, int month, int year);
#endif //DATEUTIL_H
