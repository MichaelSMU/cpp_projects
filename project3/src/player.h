#include<iostream>
#include<string>

using namespace std;

class Player {
    private:
        string name;
        int healthPts;
    public:
        Player(const string& name) : name(name), healthPts(10) { cout<<"Creating a player "<<name<<"\n"; };
        int attack {};
        void loseHP(const int& attach) {};
        string& get_name();
        int get_healthPts();
}

