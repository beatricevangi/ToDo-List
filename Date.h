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

    void checkValidity(unsigned int day, unsigned int month, unsigned int year);

    unsigned int countMonthDays(unsigned int month, unsigned int year);

public:
    Date(unsigned int day = 1, unsigned int month = 1, unsigned int year = 2022);

    std::string toString();

    unsigned int getDay() { return this->day; }

    unsigned int getMonth() { return this->month; }

    unsigned int getYear() { return this->year; }

    void setDate(unsigned int day, unsigned int month, unsigned int year);

    bool operator==(const Date &date) const;
};

#endif //LABORATORY_DATE_H
