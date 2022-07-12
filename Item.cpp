//
// Created by beatrice on 10/06/22.
//


#include "Item.h"

#include <utility>
#include "Date.h"

std::string Item::getName() const {
    return name;
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

void Item::rename(std::string name) {
    this->name = std::move(name);
}

bool Item::operator==(const Item &i) const {
    return i.name == name && i.date == date;
}
