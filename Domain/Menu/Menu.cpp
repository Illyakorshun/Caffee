#include "Menu.h"
    #include <iostream>
    #include <vector>
    
    Menu::Menu() {
        drinks = {{"Coffee", 25.0}, {"Tea", 20.0}, {"Water", 10.0}};
        hotDishes = {{"Soup", 60.0}, {"Pasta", 80.0}, {"Pizza", 100.0}, {"Burger", 70.0}, {"Steak", 120.0}};
        snacks = {{"Cake", 30.0}, {"Ice cream", 40.0}, {"Chips", 25.0}};
    }
    
    int Menu::getSize(int category) {
        if (category == 0) return drinks.size();
        if (category == 1) return hotDishes.size();
        if (category == 2) return snacks.size();
        return 0;
    }
    
    std::vector<MenuItem> Menu::getItems(int category) {
        if (category == 0) return drinks;
        if (category == 1) return hotDishes;
        if (category == 2) return snacks;
        return {};
    }