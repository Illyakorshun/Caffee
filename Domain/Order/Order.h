#ifndef ORDER_H
#define ORDER_H

#include "../Menu/Menu.h"

class Order {
public:
    Order() : size(0) {} // Initialize size to 0
    void addItem(MenuItem item);
    MenuItem* getItems();
    int getSize();
private:
    MenuItem items[10];
    int size;
};

#endif