#include<iostream>
#include<string>

using namespace std;

class base {
    public:
        base() {};
        virtual void printer() { cout<<"Hello World"; }; //virtual functions are meant to be overwritten.
        void showclass() { cout<<"I am a base class object."; }; 
};

class child : public base {
    public:
        child() {};
        void printer() { cout<<"Hello World from Child Class"; };
        void showclass() { cout<<"I am a child class object."; }; 
};

int main () {

    base* baseptr;
    child childone;

    baseptr = &childone;
    baseptr->printer();
    baseptr->showclass();

    return 0;
}