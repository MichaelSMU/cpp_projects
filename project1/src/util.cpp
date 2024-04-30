#include<iostream>
#include <cctype>

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

std::string string_to_upper(std::string s) {
    for(int i = 0; i < s.size(); i++)
        s[i] = std::toupper(s[i]);
    return s;
}

std::string string_to_lower(std::string s) {
    for(int i = 0; i < s.size(); i++)
        s[i] = std::tolower(s[i]);
    return s;
}