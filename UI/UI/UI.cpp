#include "UI.h"
#include "../../Domain/Menu/Menu.h"
#include "../../lib/lib.h"
UI::UI(Cafe* cafe, Logger* logger) : cafe(cafe), logger(logger) {
    // Constructor implementation
}

void UI::run() {
    bool running = true;
    while (running) {
        displayMenu();
        Order order = takeOrder();
        double total = cafe->calculateTotal(order);
        std::cout << "Total order amount: " << total << " UAH.\n";
        if (payOrder(total)) {
            cafe->takeOrder(order);
            std::cout << "Thank you for your order!\n";
        }
        else {
            std::cout << "Sorry, insufficient funds to complete the payment.\n";
        }
        std::cout << "Do you want to place another order? (yes/no): ";
        std::string response;
        std::cin >> response;
        if (response != "yes") {
            running = false;
        }
    }
}

void UI::displayMenu() {
    std::cout << "Menu:\n";
    MenuItem* items = cafe->getMenu()->getItems();
    for (int i = 0; i < cafe->getMenu()->getSize(); i++) {
        std::cout << i + 1 << ". " << items[i].name << " - " << items[i].price << " UAH.\n";
    }
    std::cout << "0. Exit\n";
}

Order UI::takeOrder() {
    Order order;
    int choice = 0;
    do {
        std::cout << "Select a menu item (or 0 to finish): ";
        if (std::cin >> choice) {
            if (choice > 0 && choice <= cafe->getMenu()->getSize()) {
                MenuItem item = cafe->getMenu()->getItems()[choice - 1];
                order.addItem(item);
                std::cout << item.name << " added to the order.\n";
            }
            else if (choice != 0) {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
        else {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    } while (choice != 0);
    return order;
}

bool UI::payOrder(double total) {
    double money = 0;
    std::cout << "Enter the amount to pay: ";
    if (std::cin >> money) {
        return money >= total;
    }
    else {
        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
}