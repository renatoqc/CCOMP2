#include <iostream>
#include <string>

class Dota2Item {
public:
    Dota2Item(const std::string& name, int cost, const std::string& description)
        : name_(name), cost_(cost), description_(description) {}

    void PrintInfo() const {
        std::cout << "Item: " << name_ << "\n";
        std::cout << "Cost: " << cost_ << " gold\n";
        std::cout << "Description: " << description_ << "\n";
    }

private:
    std::string name_;
    int cost_;
    std::string description_;
};

