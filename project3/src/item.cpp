#include <iostream>
#include <string>
#include "item.h"

using namespace std;

string item::get_name() { return this->name; }
double item::get_price() { return this->price; }