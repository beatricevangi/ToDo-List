//
// Created by beatrice on 10/06/22.
//


#include "Item.h"
#include "Date.h"

std::string Item::getName() const {
    return _name;
}

Date Item::getDate() const{
    return date;
}

void Item::editDate(Item &i, int day, int month, int year) {
    i.date.checkValidity(day, month, year);
    i.date.setDay(day);
    i.date.setMonth(month);
    i.date.setYear(year);
};

void Item::rename(std::string &name) {
    this->_name = name;
    //std::cout<< "Event renamed to: " << _name <<std::endl;
}

void Item::setDate(const Date &_date) {
    Item::date = _date;
};

bool Item::operator==(const Item &i) const {
    return i._name == _name && i.date == date;
}

