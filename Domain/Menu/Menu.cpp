#include "Menu.h"


Menu::Menu() : size(8) {
    items[0] = {"Coffee", 25.0};
    items[1] = {"Tea", 20.0};
    items[2] = {"Cake", 30.0};
    items[3] = {"Ice cream", 40.0};
    items[4] = {"Water", 10.0};
    items[5] = {"Pasta", 80.0};
    items[6] = {"Soup", 60.0};
    items[7] = {"Chips", 25.0};
    
}

MenuItem* Menu::getItems() {
    return items;
}

int Menu::getSize() {
    return size;
}