#ifndef UTIL_H
#define UTIL_H

#include<iostream>
#include<cctype>
#include<vector>

using namespace std;

int get_number();
void printer(int n);
string string_to_upper(std::string s);
string string_to_lower(std::string s);
vector<string> splitString(const string& s, char delimiter);
vector<int> convertStringVectorToInt(const vector<string>& stringVec);

#endif