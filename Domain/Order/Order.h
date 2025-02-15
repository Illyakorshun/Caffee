#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "../Menu/Menu.h" // Corrected include path for MenuItem

class Order {
public:
    void addItem(const MenuItem& item); // Passing by reference to avoid unnecessary copies
    const std::vector<MenuItem>& getItems() const; // Return a reference to avoid unnecessary copies
    int getSize() const; // Mark as const

private:
    std::vector<MenuItem> items;
};

#endif
