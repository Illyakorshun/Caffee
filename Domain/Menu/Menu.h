#ifndef MENU_H
#define MENU_H

#include "../../lib/lib.h"

struct MenuItem {
    std::string name;
    double price;
};

class Menu {
public:
    Menu();
    MenuItem* getItems();
    int getSize();
private:
    MenuItem items[4];
    int size;
};
#endif