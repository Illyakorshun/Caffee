#ifndef CAFE_H
#define CAFE_H

#include <memory>
#include "../Menu/Menu.h"
#include "../Order/Order.h"
#include "../Data/Data.h" // Corrected include for Data
class Cafe {
public:
    Cafe(std::shared_ptr<Menu> menu, std::shared_ptr<Data> data);
    void takeOrder(Order& order);
    std::shared_ptr<Menu> getMenu();
    double calculateTotal(const Order& order); // Pass Order by const reference to avoid unnecessary copies

private:
    std::shared_ptr<Menu> menu;
    std::shared_ptr<Data> data;
};

#endif
