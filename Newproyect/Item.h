#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
public:
    Item(const std::string& name, int cost) : name(name), cost(cost) {}

    void showInfo() {
        std::cout << "Item: " << name << ", Costo: " << cost << std::endl;
    }

private:
    std::string name;
    int cost;
};

#endif
