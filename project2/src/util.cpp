#include<iostream>
#include<cctype>
#include<vector>
#include "../include/util.h"

using namespace std;

int get_number() {

    int n;
    cout<<"Input a number: ";
    cin>>n;

    return n;
}

void printer(int n) {

    int i = 0;
    while(i<n) {

        string result = (i%2==0) ? "Good Morning." : "Good Night.";
        cout<<result<<"\n";
        i++;
    }

}

string string_to_upper(string s) {
    for(int i = 0; i < s.size(); i++)
        s[i] = std::toupper(s[i]);
    return s;
}

string string_to_lower(string s) {
    for(int i = 0; i < s.size(); i++)
        s[i] = std::tolower(s[i]);
    return s;
}

vector<string> splitString(const string& s, char delimiter) {

    vector<string> tokens;
    size_t start = 0;
    size_t end = s.find(delimiter);

    while (end != string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
        end = s.find(delimiter, start);
    }

    tokens.push_back(s.substr(start));

    return tokens;
}

vector<int> convertStringVectorToInt(const vector<string>& stringVec) {
    
    std::vector<int> intVec;
    
    for (const string& str : stringVec) {
        intVec.push_back(std::stoi(str));
    }
    
    return intVec;
}