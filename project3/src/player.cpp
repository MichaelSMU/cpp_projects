#include<iostream>
#include<string>
#include <"player.h">

using namespace std;

class Player {
    private:
        string name;
        int healthPts;
    public:
        Player(const string& name) : name(name), healthPts(10) { cout<<"Creating a player "<<name<<"\n"; };
        int attach
}