#include <iostream>
#include <ostream>
#include <string>
#include "../include/Clock.h"
#include "../include/util.h"

using namespace std;

int main() {
    // Clock a = Clock();
    // Clock b = Clock(1,2,3,4);
    // Clock c = Clock(2,3);
    // // Clock d = Clock(120001);
    // // Clock e = Clock("TUESDAY");

    // std::cout<<a<<endl;
    // std::cout<<b<<endl;
    // std::cout<<c<<endl;
    // // std::cout<<d<<endl;
    // // std::cout<<e<<endl;

    // std::cout<<a+b<<endl;
    // std::cout<<a-b<<endl;
    // std::cout<<-b<<endl;
    // std::cout<<(a>b)<<endl;
    // std::cout<<(a<b)<<endl;
    // std::cout<<(a==b)<<endl;

    Clock a = Clock(0,12,0,0);
    Clock b = Clock(0,12,0,0);
    Clock c = Clock(1);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<a+b<<endl;
    cout<<((a+b)==c ? "True" : "False")<<endl;
    // cout<<b<<endl;
    // cout<<a+b<<endl;

    return 0;
}