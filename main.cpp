#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;


unordered_map<char, int> getCharFrequency(string filename) {
    
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return unordered_map<char, int>();
    }
    
    string line;
    cout << "\n";
    unordered_map<char, int> charFrequency;
    while (getline(file, line)) {
        for (char c : line) {
            charFrequency[c]++;
        }
    }
    
    file.close();
    return charFrequency;
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    unordered_map<char, int> charFrequency = getCharFrequency(filename);

    for (auto& pair : charFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
    
}