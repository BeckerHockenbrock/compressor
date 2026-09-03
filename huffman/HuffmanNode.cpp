#include <iostream>
#include <string>

using namespace std;

class HuffmanNode{
private:
    
    char c;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
    
public: 
    
    HuffmanNode(char c, int freq, HuffmanNode* left, HuffmanNode* right){
        this->c = c;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
    
    HuffmanNode(char c, int freq){
        this->c = c;
        this->freq = freq;
        this->left = nullptr;
        this->right = nullptr;
    }

    char getChar(){
        return c;
    }

    int getFreq(){
        return freq;
    }

    HuffmanNode* getLeft(){
        return left;
    }

    HuffmanNode* getRight(){
        return right;
    }
};