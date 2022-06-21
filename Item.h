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
    //Item(std::string name, int d = 1, int m = 0, int y = 1);

    Item(std::string name, int day, int month, int year) : _name(std::move(name)), date(day, month, year) {
    }; //usando std move passo by value

    //~Item();

    void setDone(bool flag) {
        this->done = flag;
    };

    bool isDone() {
        return this->done;
    };

    std::string getName() const;

    void setDate(const Date &date);

    Date getDate() const;

    static void editDate(Item &i, int day, int month, int year);

    void rename(std::string &name);

    bool operator==(const Item &i) const;
};


#endif //LABORATORY_ITEM_H