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

void Item::editDate(int day, int month, int year) {
    this->date.setDate(day, month, year);
};

void Item::editName(std::string name) {
    this->name = std::move(name);
}

bool Item::operator==(const Item &i) const {
    return i.name == name && i.date == date;
}

std::string Item::toString() {
    std::string check = "TO DO";
    if (this->isDone())
        check = "DONE";
    return "Date: " + this->getDate().toString() + "    Status: " + check + "    Activity: " + this->getName() + "\n";
}
