#include <iostream>
#include "ToDoList.h"


int main() {
    ToDoList t;
    bool quit = false;
    int choice;

    while (!quit) {
        std::cout << std::endl;
        std::cout << "Select an option below" << std::endl;
        std::cout << "1: View list" << std::endl;
        std::cout << "2: Create a new item" << std::endl;
        std::cout << "3: Delete an item" << std::endl;
        std::cout << "4: Toggle an item" << std::endl;
        std::cout << "5: Edit the date of an item" << std::endl;
        std::cout << "6: Edit the name of an item" << std::endl;
        std::cout << "7: View items that are not completed yet" << std::endl;
        std::cout << "8: Delete already completed items" << std::endl;
        std::cout << "9: Delete all items" << std::endl;
        std::cout << "10: Set a new name for the list" << std::endl;
        std::cout << "0: Quit" << std::endl;

        std::cin >> choice;
        std::cin.ignore(1, '\n');

        try {
            switch (choice) {

                case 0: {
                    quit = true;
                    break;
                }

                case 1 : {
                    std::cout << "TO DO LIST: " << t.getName() << "!" << std::endl << std::endl;
                    std::cout << "(There are " << t.countItems() << " activities total, " << t.countItemsToBeDone()
                              << " of which are yet to be completed)" << std::endl;
                    std::cout << t.toString();
                    break;
                }

                case 2 : {
                    std::string name, d, m, y;
                    std::cout << "Enter the name of the new Item: " << std::endl;
                    std::getline(std::cin, name);
                    std::cout << "Enter day: " << std::endl;
                    std::cin >> d;
                    std::cin.ignore(100, '\n');
                    std::cout << "Enter month: " << std::endl;
                    std::cin >> m;
                    std::cin.ignore(100, '\n');
                    std::cout << "Enter year: " << std::endl;
                    std::cin >> y;
                    Item i(name, std::stoi(d), std::stoi(m), std::stoi(y));
                    t.insertItem(i);
                    std::cout << "Item created successfully." << std::endl;
                    t.updateFile();
                    break;
                }

                case 3 : {
                    std::cout << t.toString();
                    int pos;
                    std::cout << "Enter the number of the new Item you would like to delete: " << std::endl;
                    std::cin >> pos;
                    auto item = t.getItem(pos);
                    t.deleteItem(*item);
                    t.updateFile();
                    break;
                }

                case 4 : {
                    std::cout << t.toString();
                    int pos;
                    std::cout << "Enter the number of the item you would like to toggle: " << std::endl;
                    std::cin >> pos;
                    t.toggle(*t.getItem(pos));
                    t.updateFile();
                    break;
                }

                case 5 : {
                    std::cout << t.toString();
                    int pos;
                    std::cout << "Enter the number of the item you would like to edit: " << std::endl;
                    std::cin >> pos;
                    auto item = t.getItem(pos);

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
                    item->editDate(stoi(d), stoi(m), stoi(y));
                    std::cout << "Date changed successfully!" << std::endl;
                    t.updateFile();
                    break;
                }

                case 6: {
                    std::cout << t.toString();
                    int pos;
                    std::cout << "Enter the number of the item you would like to edit: " << std::endl;
                    std::cin >> pos;
                    auto item = t.getItem(pos);

                    std::cout << "Enter the new name: " << std::endl;
                    std::cin.ignore();
                    std::string newName;
                    std::getline(std::cin, newName, '\n');
                    item->editName(newName);
                    std::cout << "Item renamed successfully!" << std::endl;
                    t.updateFile();
                    break;
                }

                case 7: {
                    std::cout << "(There are " << t.countItemsToBeDone() << " activities to be completed)" << std::endl;
                    std::cout << t.toStringToBeDone();

                    break;
                }

                case 8: {
                    t.removeDone();
                    std::cout << "Operation completed successfully!" << std::endl;
                    break;
                }

                case 9: {
                    t.clearAll();
                    t.updateFile();
                    std::cout << "Operation completed successfully!" << std::endl;
                    break;
                }

                case 10: {
                    std::string newName;
                    std::cout << "Enter the new name: " << std::endl;
                    std::getline(std::cin, newName, '\n');
                    t.setName(newName);
                    std::cout << "Operation completed successfully!" << std::endl;
                    break;
                }

                default: {
                    std::cerr << "Invalid input, please enter a new one." << std::endl;
                }
            }
        }
        catch (std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
