#include "Cafe.h"

Cafe::Cafe(Menu* menu, Data* data) : menu(menu), data(data) {}

void Cafe::takeOrder(Order& order) {
    std::cout << "Order accepted. Thank you!\n";
    // Logic to save the order to a file or process it further
}

Menu* Cafe::getMenu() {
    return menu;
}

double Cafe::calculateTotal(Order& order)
{
    double total = 0;
    MenuItem* items = order.getItems();
    for (int i = 0; i < order.getSize(); i++) {
        total += items[i].price;
    }
    return total;
}