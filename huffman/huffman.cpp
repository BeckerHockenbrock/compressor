#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#include "HuffmanTree.cpp"

using namespace std;

class HuffmanCompression {
public:

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

        return sortedFreq;
    }
    
    void compress(string filename) {
        map<char, int> charFrequency = getCharFrequency(filename);
        vector<pair<char, int>> sortedFreq = sortMap(charFrequency);
        cout << "\n";
        HuffmanTree tree(sortedFreq);
        tree.printTree();
    }


    
};




