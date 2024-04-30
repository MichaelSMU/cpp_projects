#include<iostream>
#include<fstream>

using namespace std;

int main() {
    
    ofstream myFile("mytemperature");
    string mon[6] = {"jan","feb","mar","apr","may","jun"};
    int temp[6] = {40,30,50,60,70,80};

    for(int i=0; i<6; i++) {
        myFile<<mon[i]<<"\t"<<temp[i]<<"\n";
    }

    myFile.close();

    return 0;

}