#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdint>

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

    vector<uint8_t> packBits(const string& bitString, int& padding) {
        vector<uint8_t> bytes;
        uint8_t currentByte = 0;
        int bitCount = 0;
        for (char bit : bitString) {
            currentByte = (currentByte << 1) | (bit == '1' ? 1 : 0);
            bitCount++;
            if (bitCount == 8) {
                bytes.push_back(currentByte);
                currentByte = 0;
                bitCount = 0;
            }
        }

        if (bitCount > 0) {
            padding = 8 - bitCount;
            currentByte <<= padding;
            bytes.push_back(currentByte);
        } else {
            padding = 0;
        }
        return bytes;
    }

    string getBitStr(string filename, map<char, string> codes) {
    
        string str = "";

        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file" << endl;
            return "";
        }
        
        string line;
        while (getline(file, line)) {
            for (char c : line) {
                str += codes[c];
            }
        }
        
        file.close();
        return str;
    }


    
    void compress(string filename) {
        map<char, int> charFrequency = getCharFrequency(filename);
        vector<pair<char, int>> sortedFreq = sortMap(charFrequency);
        cout << "\n";
        HuffmanTree tree(sortedFreq);
        map<char, string> codes = tree.getCodes();

        cout << "\n--- Huffman Codes ---\n";
        for (const auto& pair : codes) {
            cout << "'" << pair.first << "' : " << pair.second << endl;
        }

        string bitString = getBitStr(filename,codes);

        int padding = 0;
        vector<uint8_t> bitArray = packBits(bitString, padding);

        cout << "Packed into: " << bitArray.size() << " bytes! (Padding: " << padding << " bits)\n";



    }


    
};




