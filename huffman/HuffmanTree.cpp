#pragma once
#include "HuffmanNode.cpp"
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->getFreq() > b->getFreq();
    }
};

class HuffmanTree{
    private:
    HuffmanNode* root;

    public:
    HuffmanTree(vector<pair<char, int>> sortedFreq){
        buildTree(sortedFreq);
    }

    void printTree(){
        printTree(root);
    }

    void printTree(HuffmanNode* node, string indent = "", string branch = "Root: ") {
        if (node == nullptr) return;
    
        cout << indent << branch;
        if (node->getLeft() == nullptr && node->getRight() == nullptr) {
            if (node->getChar() == ' ') cout << "[SPACE]";
            else if (node->getChar() == '\n') cout << "[NEWLINE]";
            else cout << "'" << node->getChar() << "'";
            cout << " (" << node->getFreq() << ")" << endl;
        } else {
            cout << "[Internal: " << node->getFreq() << "]" << endl;
        }
    
        printTree(node->getLeft(), indent + "  ", "L: ");
        printTree(node->getRight(), indent + "  ", "R: ");
    }

    HuffmanNode* getRoot(){
        return root;
    }

    void buildTree(const vector<pair<char, int>>& sortedFreq){
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

        for (const auto& p : sortedFreq) {
            minHeap.push(new HuffmanNode(p.first, p.second));
        }

        while (minHeap.size() > 1) {
            HuffmanNode* left = minHeap.top();
            minHeap.pop();

            HuffmanNode* right = minHeap.top();
            minHeap.pop();

            HuffmanNode* parent = new HuffmanNode('\0', left->getFreq() + right->getFreq(), left, right);
            minHeap.push(parent);
        }

        if (!minHeap.empty()) {
            this->root = minHeap.top();
        }
    }

     void generateCodes(HuffmanNode* node, string code, map<char, string>& huffmanCodes) {
        if (node == nullptr) {
            return;
        }
    
        // 1. Check if this is a leaf node (both left and right are nullptr)
        if (node->getLeft() == nullptr && node->getRight() == nullptr) {
            huffmanCodes[node->getChar()] = code;
            return;
        }
    
        // 2. Recurse left with '0'
        generateCodes(node->getLeft(), code + "0", huffmanCodes);
    
        // 3. Recurse right with '1'
        generateCodes(node->getRight(), code + "1", huffmanCodes);
    }

    map<char, string> getCodes() {
        map<char, string> huffmanCodes;
        generateCodes(root, "", huffmanCodes);
        return huffmanCodes;
    }

};