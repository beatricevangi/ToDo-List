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
    std::string _name;
    Date date;
    bool done = false;

public:

    Item(std::string name = " ", int day = 1, int month = 1, int year = 1) : _name(std::move(name)), date(day, month, year) {}; //usando std move passo by value

    void setDone(bool flag) { this->done = flag; };

    bool isDone() { return this->done; };

    std::string getName() const;

    void setDate(const Date &date);

    Date getDate() const;

    static void editDate(Item &i, int day, int month, int year);

    void rename(std::string name);

    bool operator==(const Item &i) const;

    virtual ~Item();
};


#endif //LABORATORY_ITEM_H