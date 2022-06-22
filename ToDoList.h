//
// Created by beatrice on 10/06/22.
//

#ifndef LABORATORY_TODOLIST_H
#define LABORATORY_TODOLIST_H

#include <utility>
#include <list>
#include "Item.h"

class ToDoList {
private:
    std::list<Item> list;

public:
    const std::list<Item> &getList() const;

public:
    ToDoList();

    void init();

    void deleteItem(Item &i);

    void insertItem(Item &i);

    void modifyItem(Item &i);

    void display();

    void updateFile();

   // std::list<Item>::iterator find(std::string name);
    Item getItemNOTWORKING(int pos);

    std::list<Item>::iterator getItem(int pos);

    void checkValidityItem(int pos, const std::string& operation);

    void displayToDo();

    void removeDone();
};


#endif //LABORATORY_TODOLIST_H
