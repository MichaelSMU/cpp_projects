#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}


int main() {

    string filename = "daily-treasury-rate.csv"; // Change the filename as per your CSV file
    
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }
    
    string line;
    vector<vector<string> > data; // 2D vector to hold CSV data
    
    while (getline(file, line)) {
        vector<string> row = split(line, ','); // assuming CSV is comma-separated
        data.push_back(row);
    }
    
    file.close();
    
    for (const string &row : data) {
        for (const string &col : row) {
            cout << col << "\t";
        }
        cout << endl;
    }
    
    return 0;
}