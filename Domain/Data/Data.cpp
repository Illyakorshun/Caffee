#include "Data.h"
#include "../lib/lib.h"


void Data::saveData(std::string filename, std::string data) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << data;
        file.close();
    }
    else {
        std::cerr << "Error opening file for saving data.\n";
    }
}

std::string Data::loadData(std::string filename) {
    std::ifstream file(filename);
    std::string data = "";
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            data += line + "\n";
        }
        file.close();
    }
    else {
        std::cerr << "Error opening file for loading data.\n";
    }
    return data;
}