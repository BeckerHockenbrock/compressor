#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


map<char, int> getCharFrequency(string filename) {
    
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return map<char, int>();
    }
    
    string line;
    cout << "\n";
    map<char, int> charFrequency;
    while (getline(file, line)) {
        for (char c : line) {
            charFrequency[c]++;
        }
    }
    
    file.close();
    return charFrequency;
}

vector<pair<char, int>> sortMap(const map<char, int>& charFrequency) {
    // 1. Copy map entries into a vector of pairs
    vector<pair<char, int>> sortedFreq(charFrequency.begin(), charFrequency.end());
    // 2. Sort the vector by frequency (pair.second) in ascending order
    sort(sortedFreq.begin(), sortedFreq.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    // 3. Return the sorted vector!
    return sortedFreq;
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    map<char, int> charFrequency = getCharFrequency(filename);
    vector<pair<char, int>> sortedFreq = sortMap(charFrequency);

    for (auto& pair : sortedFreq) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
    
}