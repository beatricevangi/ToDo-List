//
// Created by beatrice on 10/06/22.
//

#include "Date.h"

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    checkValidity(day, month, year);
    this->day = day;
    this->month = month;
    this->year = year;
}

unsigned int Date::countMonthDays(unsigned int month, unsigned int year) {
    static int array[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayCounter = array[month - 1];
    if ((month == 2) && (year % 4 == 0) && ((year) % 100 != 0 || (year) % 400 == 0))
        dayCounter = 29;
    return dayCounter;
}

void Date::checkValidity(unsigned int day, unsigned int month, unsigned int year) {
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > countMonthDays(month, year)) {
        throw std::runtime_error("Illegal date!");
    }
}

bool Date::operator==(const Date &date) const {
    return date.day == day && date.month==month && date.year == year;
}

void Date::setDate(unsigned int day, unsigned int month, unsigned int year){
    checkValidity(day, month, year);
    this->day = day;
    this->month = month;
    this->year = year;
}

std::string Date::toString() {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}
