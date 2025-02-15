#ifndef UI_H
#define UI_H

#include "../../../Domain/Cafe/Cafe.h"
#include "../../../Domain/Order/Order.h"
#include "../Logger/Logger.h"
#include <memory>

class UI {
public:
    UI(std::shared_ptr<Cafe> cafe, std::shared_ptr<Logger> logger);
    void run();
    void displayMenu();
    Order takeOrder();
    bool payOrder(double total);

private:
    std::shared_ptr<Cafe> cafe;
    std::shared_ptr<Logger> logger;
};

#endif
