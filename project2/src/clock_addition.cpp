#include <iostream>
#include <ostream>
#include <string>
#include "Clock.h"
#include "util.h"

using namespace std;

int main(int argc, char* argv[]) {

    Clock out = Clock();
    Clock c;

    for (int i = 1; i < argc; ++i) {
        
        vector<string> svec = splitString(argv[i],',');
        vector<int> ivec = convertStringVectorToInt(svec);
        int size = ivec.size();
        
        switch(size) {
            case 1:
                c = Clock(ivec[0]);
                break;
            case 2:
                c = Clock(ivec[0],ivec[1]);
                break;
            case 4:
                c = Clock(ivec[0],ivec[1],ivec[2],ivec[3]);
                break;
            default:
                c = Clock();
                break;
        };

        cout<<"Time "<<i<<": "<<c;
        out = out + c;
    }

    cout<<"Sum of Time: "<<out<<"\n";

    return 0;
}