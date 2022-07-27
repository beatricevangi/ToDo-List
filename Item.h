//
// Created by beatrice on 10/06/22.
//

#ifndef LABORATORY_ITEM_H
#define LABORATORY_ITEM_H

#include <string>
#include <utility>
#include "Date.h"

class Item {
private:
    std::string name;
    Date date;
    bool done = false;

public:
    Item(std::string name = " ", int day = 1, int month = 1, int year = 1) : name(std::move(name)), date(day, month, year) {};

    ~Item() = default;

    void setDone(bool flag) { this->done = flag; };

    bool isDone() const { return this->done; };

    std::string getName() const;

    Date getDate() const;

    void editDate(int day, int month, int year);

    void editName(std::string name);

    std::string toString() const;

    bool operator==(const Item &i) const;
};


#endif //LABORATORY_ITEM_H