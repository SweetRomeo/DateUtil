//
// Created by b00877391 on 7/12/2024.
//

#ifndef DATEUTIL_H
#define DATEUTIL_H
#include <stdbool.h>
bool isLeapYear(int year);
bool isValidDate(int day, int month, int year);
int getDayOfYear(int day, int month, int year);
int getTotalDays(int year, int totalDays);
int getDayOfWeek(int day, int month, int year);
void printDateByDayOfWeekTR(int day, int month, int year, int dayOfWeek);
void printDateByDayOfWeekEN(int day, int month, int year, int dayOfWeek);
void printDateByDayOfWeekDE(int day, int month, int year, int dayOfWeek);
void printDateTR(int day, int month, int year);
void printDateEN(int day, int month, int year);
void printDateDE(int day, int month, int year);
#endif //DATEUTIL_H
