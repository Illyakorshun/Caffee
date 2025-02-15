#ifndef DATA_H
#define DATA_H
#include "../lib/lib.h"

class Data {
public:
    void saveData(std::string filename, std::string data);
    std::string loadData(std::string filename);
};

#endif