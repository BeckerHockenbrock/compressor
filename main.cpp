#include <iostream>
#include <fstream>
#include <string>
#include "huffman.cpp"

using namespace std;


int main() {
    
    HuffmanCompression huffman;
    huffman.compress("test.txt");
    return 0;
}