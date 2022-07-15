//
// Created by beatrice on 10/06/22.
//

#ifndef LABORATORY_TODOLIST_H
#define LABORATORY_TODOLIST_H

#include <utility>
#include <list>
#include <iostream>
#include "Item.h"

class ToDoList {
private:
    std::list<Item> list;
    std::string name;
    std::string file_path = "../File.txt";

public:
    const std::string &getName() const;

    ToDoList();

    ~ToDoList() = default;

    void setName(const std::string &name);

    std::list<Item>::iterator getItem(int pos);

    void deleteItem(Item &i);

    void insertItem(Item &i);

    void toggle(Item &i);

    int countItems();

    int countItemsToBeDone();

    void updateFile();

    void removeDone(); //cancella attività completate

    void clearAll();

    std::string toString();

    std::string toStringToBeDone(); //ritorna una stringa delle attività da fare
};


#endif //LABORATORY_TODOLIST_H
