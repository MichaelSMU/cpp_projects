#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class car {
    private:
        string brand;
    public:
        car(const string& s) : brand(s) {};
};

int main() {

    car a("Honda");
    bool myBoolean = false;    

    string line;
    ifstream myFile("temperature.txt");
    while (getline(myFile, line)) {
        cout<<line<<"\n";
    }

    return 0;
}

