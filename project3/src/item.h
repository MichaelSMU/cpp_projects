#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class item {
    protected: 
        std::string name;
        double price;
    public:
        item(const string& name, const double& price):  name(name), price(price)
        string get_name();
        double get_price();
        ~item();
        
};

#endif
