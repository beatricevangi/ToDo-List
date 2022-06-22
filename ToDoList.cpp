//
// Created by beatrice on 10/06/22.
//

#include <fstream>
#include "ToDoList.h"
#include <algorithm>

ToDoList::ToDoList() {
    init();
}

void ToDoList::init() {
    std::fstream my_file;
    my_file.open("/home/beatrice/CLionProjects/Laboratory/File.txt", std::ios::in);
    if (!my_file) {
        std::cerr << "Error: file could not be opened" << std::endl;
    } else {
        while (!my_file.eof()) {                        // keep reading until end-of-file
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
}

void ToDoList::deleteItem(Item &i) {
    list.remove(i);
    updateFile();
}

void ToDoList::insertItem(Item &item) {
    list.push_back(item);
}


void ToDoList::updateFile() {
    std::ofstream my_file;
    my_file.open("/home/beatrice/CLionProjects/Laboratory/File.txt", std::ios::out);

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

void ToDoList::modifyItem(Item &i) {    //TODO FARE CONTROLLO SU POSIZIONE ALTROVE E MEGLIO
    bool isPresent = false;
    for (const auto &tmp : list) {
        if (tmp == i) {
            isPresent = true;
        }
    }
    if (isPresent) {

        std::cout << "Select an option below: " << std::endl;
        std::cout << "1: Rename Item" << std::endl;
        std::cout << "2: Edit Date " << std::endl;
        std::cout << "3: Mark as done/todo an Item" << std::endl;
        std::cout << "0: Quit" << std::endl;

        int choice;
        std::cin >> choice;
        switch (choice) {
            case 0 : {
                break;
            }

            case 1: {
                std::cout << "Enter the new name: " << std::endl;
                std::cin.ignore();
                std::string newName;
                std::getline(std::cin, newName, '\n');

                //std::cin >> newName;
                //std::cin.ignore(1, '\n');
                i.rename(newName);

                std::cout << "Item renamed successfully!" << std::endl;
                updateFile();
                break;
            }

            case 2: {
                std::string d, m, y;
                std::cout << "Enter day: " << std::endl;
                std::cin >> d;
                std::cin.ignore(1, '\n');
                std::cout << "Enter month: " << std::endl;
                std::cin >> m;
                std::cin.ignore(1, '\n');
                std::cout << "Enter year: " << std::endl;
                std::cin >> y;
                std::cin.ignore(1, '\n');
                Item::editDate(i, stoi(d), stoi(m), stoi(y));

                std::cout << "Date changed successfully!" << std::endl;
                updateFile();
                break;
            }

            case 3: {
                bool flag = i.isDone();
                i.setDone(!flag);
                std::cout << "Item edited successfully!" << std::endl;
                updateFile();
                break;
            }

            default: {
                std::cerr << "Invalid input, please enter a new one." << std::endl;
            }
        }
    } else
        std::cerr << "Error: the item you are trying to edit is not present in the list" << std::endl;
}

void ToDoList::display() {
    std::cout << "------------------------ T O   D O   L I S T ------------------------" << std::endl;
    int i = 1;
    for (Item tmp : list) {
        std::cout << "ITEM " << i << ":    ";
        tmp.getDate().displayDate();
        std::cout << "     ";
        if (tmp.isDone()) {
            std::cout << "DONE";
        } else
            std::cout << "TO DO";
        std::cout << "     ";
        std::cout << tmp.getName() << std::endl;
        i++;
    }
}

void ToDoList::displayToDo() {
    int i = 1;
    for (Item tmp : list) {
        if (!tmp.isDone()) {
            std::cout << "ITEM " << i << ":    ";
            tmp.getDate().displayDate();
            std::cout << "     TO DO     ";
            std::cout << tmp.getName() << std::endl;
        }
        i++;
    }
}

void ToDoList::removeDone() {
    int size = list.size();
    for (int i = size; i > 0; i--) {
        auto item = getItem(i);
        if (item->isDone())
            deleteItem(*item);
    }

}

const std::list<Item> &ToDoList::getList() const {
    return list;
}

Item ToDoList::getItemNOTWORKING(int pos) {
    std::_List_iterator<Item> it = list.begin();
    std::advance(it, pos - 1);
    return *it;
}

std::list<Item>::iterator ToDoList::getItem(int pos) {
    std::_List_iterator<Item> it = list.begin();
    std::advance(it, pos - 1);
    return it;
}

void ToDoList::checkValidityItem(int pos, const std::string &operation) {
    if (pos <= list.size() && pos > 0) {
        auto item = getItem(pos);
        if (operation == "edit") {
            modifyItem(*item);
        } else if (operation == "delete") {
            deleteItem(*item);
            std::cout << "Item deleted successfully." << std::endl;

        } else if (operation == "check") {
            item->setDone(true);
            std::cout << "Operation completed successfully" << std::endl;

        }
    } else
        std::cerr << "Operation failed, invalid input";
}
