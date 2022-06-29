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

unsigned int Date::countMonthDays(unsigned int _month, unsigned int _year) {
    static int array[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayCounter = array[_month - 1];
    if ((_month == 2) && (_year % 4 == 0) && ((_year) % 100 != 0 || (_year) % 400 == 0))
        dayCounter = 29;
    return dayCounter;
}

void Date::checkValidity(unsigned int _day, unsigned int _month, unsigned int _year) {
    if (_year < 0 || _month < 1 || _month > 12 || _day < 1 || _day > countMonthDays(_month, _year)) {
        throw std::runtime_error("Illegal date!");
    }
}

void Date::displayDate() {
    std::cout << day << "/" << month << "/" << year;
}

bool Date::operator==(const Date &date) const {
    return date.day == day && date.month==month && date.year == year;
}
