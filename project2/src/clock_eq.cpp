#include <iostream>
#include <ostream>
#include <string>
#include "../include/Clock.h"
#include "../include/util.h"

using namespace std;

int main(int argc, char* argv[]) {

    Clock a, b;

    vector<string> svec = splitString(argv[1],',');
    vector<int> ivec = convertStringVectorToInt(svec);
    int size = ivec.size();
    
    switch(size) {
        case 1:
            a = Clock(ivec[0]);
            break;
        case 2:
            a = Clock(ivec[0],ivec[1]);
            break;
        case 4:
            a = Clock(ivec[0],ivec[1],ivec[2],ivec[3]);
            break;
        default:
            a = Clock();
            break;
    };
    
    cout<<"Time 1: "<<a;

    if (argc<3) {

        b = Clock(); 

    } else {

        vector<string> svec = splitString(argv[2],',');
        vector<int> ivec = convertStringVectorToInt(svec);
        int size = ivec.size();
        
        switch(size) {
            case 1:
                b = Clock(ivec[0]);
                break;
            case 2:
                b = Clock(ivec[0],ivec[1]);
                break;
            case 4:
                b = Clock(ivec[0],ivec[1],ivec[2],ivec[3]);
                break;
            default:
                b = Clock();
                break;
        };
    }

    cout<<"Time 2: "<<b;
    cout<<"Time 1 equals to Time 2: "<<((a==b) ? "True" : "False")<<"\n";

    return 0;
}