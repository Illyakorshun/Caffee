#ifndef CAFE_H
#define CAFE_H

#include "../Order/Order.h"
#include "../Menu/Menu.h"
#include "../../Data/Data.h"


class Cafe {
public:
    Cafe(Menu* menu, Data* data);
    void takeOrder(Order& order);
    Menu* getMenu();
    double calculateTotal(Order& order);
private:
    Menu* menu;
    Data* data;
};

#endif