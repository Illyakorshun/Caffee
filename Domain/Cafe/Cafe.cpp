#include "Cafe.h"
#include <iostream>

Cafe::Cafe(std::shared_ptr<Menu> menu, std::shared_ptr<Data> data) : menu(menu), data(data) {}

void Cafe::takeOrder(Order& order) {
    std::cout << "Order accepted. Thank you!\n";
    // Logic to save the order to a file or process it further
}

std::shared_ptr<Menu> Cafe::getMenu() {
    return menu;
}

double Cafe::calculateTotal(const Order& order) {
    double total = 0;
    for (const auto& item : order.getItems()) {
        total += item.price;
    }
    return total;
}
