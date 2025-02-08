// Order.cpp
#include "Order.h"

void Order::addItem(MenuItem item) {
    items[size++] = item;
}

MenuItem* Order::getItems() {
    return items;
}

int Order::getSize() {
    return size;
}