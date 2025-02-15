#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

struct MenuItem {
    std::string name;
    double price;
};

class Menu {
private:
    std::vector<MenuItem> drinks;
    std::vector<MenuItem> hotDishes;
    std::vector<MenuItem> snacks;

public:
    Menu();
    void showCategoryMenu();
    void showItems(int category);
    void continueToNextMenu();
    int getSize(int category);  
    std::vector<MenuItem> getItems(int category);
};

#endif