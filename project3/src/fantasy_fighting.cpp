#include<iostream>
#include<string>
#include "item.h"


using namespace std;

int main() {

    item a("hahah",20);
    cout<<a.get_name()<<"\n";
    cout<<a.get_price()<<"\n";

    return 0;
}