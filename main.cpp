#include <iostream>
#include "ToDoList.h"


int main() {
    ToDoList t;
    bool quit = false;
    int choice;
    std::cout << "WELCOME!" << std::endl;

    while (!quit) {
        std::cout << std::endl;
        std::cout << "Select an option below" << std::endl;
        std::cout << "1: View list" << std::endl;
        std::cout << "2: Create a new item" << std::endl;
        std::cout << "3: Delete an item" << std::endl;
        std::cout << "4: Set an item as done" << std::endl;
        std::cout << "5: Edit an item" << std::endl;
        std::cout << "6: View items that are not completed" << std::endl;
        std::cout << "7: Delete already completed items " << std::endl;
        std::cout << "0: Quit" << std::endl;

        std::cin >> choice;
        std::cin.ignore(1, '\n');

        switch (choice) {

            case 0: {
                quit = true;
                break;
            }

            case 1 : {
                t.display();
                break;
            }

            case 2 : {
                std::string name, d, m, y;
                std::cout << "Enter the name of the new Item: " << std::endl;
                std::getline(std::cin, name);
                //std::cin.ignore(100, '\n');
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
                t.display();
                int pos;
                std::cout << "Enter the number of the new Item you would like to delete: " << std::endl;
                std::cin >> pos;
                t.checkValidityItem(pos, "delete");
                t.updateFile();
                break;
            }

            case 4 : {
                t.display();
                int pos;
                std::cout << "Enter the number of the item you would like to checkkk: " << std::endl;
                std::cin >> pos;
                t.checkValidityItem(pos, "check");
                t.updateFile();
                break;
            }

            case 5 : {
                t.display();
                int pos;
                std::cout << "Enter the number of the item you would like to edit: " << std::endl;
                std::cin >> pos;
                t.checkValidityItem(pos, "edit");
                t.updateFile();
                break;
            }

            case 6: {
                t.displayToDo();
                break;
            }

            case 7: {
                t.removeDone();
                std::cout << "Operation completed!" << std::endl;
                break;
            }

            default: {
                std::cerr << "Invalid input, please enter a new one." << std::endl;
            }
        }
    }
}