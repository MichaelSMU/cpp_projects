#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {

// key, value pairs
    map<string, int> myMap;

// insert values
    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;

// looping
    map<string, int>::iterator myiterator = myMap.begin();
    while(myiterator != myMap.end()) {
        cout<<myiterator->second<<endl;
        myiterator++; 
    }

    return 0;
}