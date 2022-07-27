//
// Created by beatrice on 10/06/22.
//

#include <fstream>
#include "ToDoList.h"

ToDoList::ToDoList() {
    std::fstream my_file;
    my_file.open(file_path, std::ios::in);

    if (!my_file) {
        std::cerr << "Error: file could not be opened" << std::endl;
    } else {
        while (!my_file.eof()) {
            std::string temporary, d, m, y, completed;

            while (std::getline(my_file, temporary)) {
                if (temporary.empty()) {
                    break;
                }
                std::getline(my_file, d);
                std::getline(my_file, m);
                std::getline(my_file, y);
                std::getline(my_file, completed);

                Item item(temporary, stoi(d), stoi(m), stoi(y));
                if (stoi(completed) == 1) {
                    item.setDone(true);
                }
                insertItem(item);
            }
        }
        my_file.close();
    }
    this->name = "Summer to-dos";
}

void ToDoList::deleteItem(Item &i) {
    list.remove(i);
}

void ToDoList::insertItem(Item &item) {
    list.push_back(item);
}

void ToDoList::updateFile() {
    std::ofstream my_file;
    my_file.open(file_path, std::ios::out);

    for (auto item : list) {
        my_file << item.getName() << std::endl;
        my_file << item.getDate().getDay() << std::endl;
        my_file << item.getDate().getMonth() << std::endl;
        my_file << item.getDate().getYear() << std::endl;
        my_file << item.isDone() << std::endl;
        my_file << std::endl;
    }
    my_file.close();
}

void ToDoList::removeDone() {
    int size = list.size();
    for (int i = size; i > 0; i--) {
        auto item = getItem(i);
        if (item->isDone())
            deleteItem(*item);
    }
    updateFile();
}

void ToDoList::clearAll() {
    int length = list.size();
    for (int i = 0; i < length; i++) {
        auto item = getItem(1);
        deleteItem(*item);
    }
}

std::list<Item>::iterator ToDoList::getItem(int pos)  {
    if (pos <= list.size() && pos > 0) {
        std::_List_iterator<Item> it = list.begin();
        std::advance(it, pos - 1);
        return it;
    } else
        throw std::runtime_error("Invalid input!");
}

void ToDoList::setName(const std::string &name) {
    ToDoList::name = name;
}

void ToDoList::toggle(Item &i) {
    i.setDone(!i.isDone());
}


int ToDoList::countItems() {
    return list.size();
}

int ToDoList::countItemsToBeDone() {
    int counter = 0;
    for (int i = 1; i <= list.size(); i++) {
        auto item = getItem(i);
        if (!item->isDone())
            counter++;
    }
    return counter;
}

const std::string &ToDoList::getName() const {
    return name;
}

std::string ToDoList::toString() const {
    std::string str;
    int i = 1;
    for (auto item : list) {
        str += std::to_string(i) + ")    " + item.toString();
        i++;
    }
    if (i == 1)
        std::cout << "List is empty!" << std::endl;
    return str;
}

std::string ToDoList::toStringToBeDone() const {
    std::string str;
    for (auto item : list) {
        if (!item.isDone()) {
            str += item.toString();
        }
    }
    return str;
}
