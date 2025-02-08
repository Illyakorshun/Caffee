#include "Menu.h"


Menu::Menu() : size(4) {
    items[0] = {"Coffee", 25.0};
    items[1] = {"Tea", 20.0};
    items[2] = {"Cake", 30.0};
    items[3] = {"Ice cream", 40.0};
}

MenuItem* Menu::getItems() {
    return items;
}

int Menu::getSize() {
    return size;
}