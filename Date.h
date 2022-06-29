//
// Created by beatrice on 10/06/22.
//

#ifndef LABORATORY_DATE_H
#define LABORATORY_DATE_H

#include <iostream>

class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;

public:
    Date(unsigned int day = 1, unsigned int month = 1, unsigned int year = 2022);

    static void checkValidity(unsigned int _day, unsigned int _month, unsigned int _year);

    static unsigned int countMonthDays(unsigned int month, unsigned int year);

    void displayDate();

    unsigned int getDay() { return this->day; }

    unsigned int getMonth() { return this->month; }

    unsigned int getYear() { return this->year; }

    void setDay(unsigned int _day) { Date::day = _day; }

    void setMonth(unsigned int _month) { Date::month = _month; }

    void setYear(unsigned int _year) { Date::year = _year; }

    bool operator==(const Date &date) const;
};

#endif //LABORATORY_DATE_H
