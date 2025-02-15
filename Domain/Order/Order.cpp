#include "Order.h"

void Order::addItem(const MenuItem& item) {
    items.push_back(item);
}

const std::vector<MenuItem>& Order::getItems() const {
    return items;
}

int Order::getSize() const {
    return items.size();
}
