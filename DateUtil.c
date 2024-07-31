//
// Created by b00877391 on 7/12/2024.
//
#include "DateUtil.h"
#include <stdio.h>

int dayOfMonths[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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

int getDayOfYear(int day, int month, int year) {

    if(!isValidDate(day, month, year)) {
        return -1;
    }
    int totalDays = day;

    switch (month - 1) {
        case 11:
            totalDays += 30;
        case 10:
            totalDays += 31;
        case 9:
            totalDays += 30;
        case 8:
            totalDays += 31;
        case 7:
            totalDays += 31;
        case 6:
            totalDays += 30;
        case 5:
            totalDays += 31;
        case 4:
            totalDays += 30;
        case 3:
            totalDays += 31;
        case 2:
            totalDays += 28;
            if(isLeapYear(year)) {
                totalDays++;
            }
        case 1:
            totalDays += 31;
    }
    return totalDays;
}

int getTotalDays(int year, int totalDays) {
    for(int y = 1900; y < year; ++y) {
        totalDays += 365;
        if(isLeapYear(y)) {
            ++totalDays;
        }
    }
    return totalDays;
}

int getDayOfWeek(int day, int month, int year) {
    int totalDays;

    if (year < 1900 || (totalDays = getDayOfYear(day, month, year)) == -1)
        return -1;

    return getTotalDays(year, totalDays) % 7;
}

void printDateByDayOfWeekTR(int day, int month, int year, int dayOfWeek) {
    switch (dayOfWeek) {
        case 0:
            printf("%02d/%02d/%04d Pazar\n", day, month, year);
        break;
        case 1:
            printf("%02d/%02d/%04d Pazartesi\n", day, month, year);
        break;
        case 2:
            printf("%02d/%02d/%04d Sali\n", day, month, year);
        break;
        case 3:
            printf("%02d/%02d/%04d Carsamba\n", day, month, year);
        break;
        case 4:
            printf("%02d/%02d/%04d Persembe\n", day, month, year);
        break;
        case 5:
            printf("%02d/%02d/%04d Cuma\n", day, month, year);
        break;
        case 6:
            printf("%02d/%02d/%04d Cumartesi\n", day, month, year);
    }
}

void printDateByDayOfWeekEN(int day, int month, int year, int dayOfWeek) {
    switch (dayOfWeek) {
        case 0:
            printf("%02d/%02d/%04d Sunday\n", day, month, year);
        break;
        case 1:
            printf("%02d/%02d/%04d Monday\n", day, month, year);
        break;
        case 2:
            printf("%02d/%02d/%04d Tuesday\n", day, month, year);
        break;
        case 3:
            printf("%02d/%02d/%04d Wednesday\n", day, month, year);
        break;
        case 4:
            printf("%02d/%02d/%04d Thursday\n", day, month, year);
        break;
        case 5:
            printf("%02d/%02d/%04d Friday\n", day, month, year);
        break;
        case 6:
            printf("%02d/%02d/%04d Saturday\n", day, month, year);
    }
}

void printDateTR(int day, int month, int year) {

    int dayOfWeek = getDayOfWeek(day, month, year);

    if(dayOfWeek == -1) {
        printf("Gecersiz Tarih\n");
        return;
    }

    printDateByDayOfWeekTR(day, month, year, dayOfWeek);
}

void printDateEN(int day, int month, int year) {

    int dayOfWeek = getDayOfWeek(day, month, year);

    if(dayOfWeek == -1) {
        printf("Invalid Date\n");
        return;
    }

    printDateByDayOfWeekEN(day, month, year, dayOfWeek);
}

