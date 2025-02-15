#include "UI.h"
#include "../../../Domain/Menu/Menu.h"
#include "../../lib/lib.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>

UI::UI(std::shared_ptr<Cafe> cafe, std::shared_ptr<Logger> logger) : cafe(cafe), logger(logger) {}

void UI::run() {
    std::string username;
    std::cout << "Enter your name: ";
    std::getline(std::cin, username);  // No need for std::cin.ignore()

    bool running = true;
    while (running) {
        displayMenu();
        Order order = takeOrder();
        double total = cafe->calculateTotal(order);
        std::cout << "Total order amount: " << total << " UAH.\n";

        if (payOrder(total)) {
            cafe->takeOrder(order);
            std::cout << "Thank you for your order!\n";

            std::ofstream file("order_history.txt", std::ios::app);
            if (file) {
                time_t now = time(nullptr);
                tm* localTime = localtime(&now);

                // Use strftime for better time formatting control
                char timeBuffer[80];
                strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", localTime);
                
                file << "Customer: " << username << "\n";
                file << "Order Time: " << timeBuffer << "\n";
                file << "Items: \n";

                for (const auto& item : order.getItems()) {
                    file << "- " << item.name << " - " << item.price << " UAH\n";
                }

                // Expected delivery time (5 minutes later)
                time_t deliveryTime = now + (5 * 60);  // 5 minutes
                tm* deliveryLocalTime = localtime(&deliveryTime);
                strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", deliveryLocalTime);
                file << "Expected Ready Time: " << timeBuffer << "\n";
                file << "-------------------------\n";
                file.close();
            } else {
                std::cerr << "Error: Unable to open file for writing.\n";
            }

            std::cout << "Please wait 5 minutes for your order.\n";
        } else {
            std::cout << "Sorry, insufficient funds to complete the payment.\n";
        }

        // Asking if the user wants to place another order
        std::cout << "Do you want to place another order? (yes/no): ";
        std::string response;
        std::cin >> response;

        // Convert response to lowercase to make it case-insensitive
        std::transform(response.begin(), response.end(), response.begin(), ::tolower);

        if (response != "yes") {
            running = false;
        }
    }
}
