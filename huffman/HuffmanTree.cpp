#include "HuffmanNode.cpp"
#include <iostream>

using namespace std;

class HuffmanTree{
    private:
    HuffmanNode* root;

    public:
    HuffmanTree(HuffmanNode* root){
        this->root = root;
    }

    void printTree(){
        printTree(root);
    }

    void printTree(HuffmanNode* node){
        if (node == nullptr){
            return;
        }
        cout << node->getChar() << " " << node->getFreq() << endl;
        printTree(node->getLeft());
        printTree(node->getRight());
    }

    HuffmanNode* getRoot(){
        return root;
    }
};